// https://www.bfilipek.com/2020/02/inidicators.html

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <type_traits>
#include "termcolor.hpp"
#include <thread>
#include <atomic>

namespace indicatorstrain
{
class ProgressBar
{
public:
  void set_progress(float value)
  {
    std::unique_lock<std::mutex> lock{mutex_}; // CTAD (C++17)
    progress_ = value;
  }
  void set_bar_width(size_t width)
  {
    std::unique_lock<std::mutex> lock{mutex_};
    bar_width_ = width;
  }

  void fill_bar_progress_with(const std::string &chars)
  {
    std::unique_lock<std::mutex> lock{mutex_};
    fill_ = chars;
  }

  void fill_bar_remainder_with(const std::string &chars)
  {
    std::unique_lock<std::mutex> lock{mutex_};
    remainder_ = chars;
  }

  void set_status_text(const std::string &status)
  {
    std::unique_lock<std::mutex> lock{mutex_};
    status_text_ = status;
  }

  void update(float value, std::ostream &os = std::cout)
  {
    set_progress(value);
    write_progress(os);
  }

  void write_progress(std::ostream &os = std::cout)
  {
    std::unique_lock<std::mutex> lock{mutex_};

    // No need to write once progress is 100%
    if (progress_ > 100.0f)
      return;

    // Move cursor to the first position on the same line and flush
    os << "\r" << std::flush;

    // Start bar
    os << "[";

    const auto completed = static_cast<size_t>(progress_ * static_cast<float>(bar_width_) / 100.0);
    for (size_t i = 0; i < bar_width_; ++i)
    {
      if (i <= completed)
        os << fill_;
      else
        os << remainder_;
    }

    // End bar
    os << "]";

    // Write progress percentage
    os << " " << std::min(static_cast<size_t>(progress_), size_t(100)) << "%";

    // Write status text
    os << " " << status_text_;
  }

private:
  std::mutex mutex_;
  float progress_{0.0f};
  size_t bar_width_{60};
  std::string fill_{"#"}, remainder_{" "}, status_text_{""};
};

template <typename Indicator, size_t count>
class MultiProgress
{
public:
  template <typename... Indicators, typename = typename std::enable_if<(sizeof...(Indicators) == count)>>
  explicit MultiProgress(Indicators &... bars) : bars_({bars...})
  {
  }
  // template <size_t index>
  // typename std::enable_if<(index >= 0 && index < count), void>
  // update(float value, std::ostream &os = std::cout)
  // {
  //   bars_[index].get().set_progress(value);
  // }

  template <size_t index>
  typename std::enable_if<(index >= 0 && index < count), void>::type
  update(float value, std::ostream &os = std::cout)
  {
    bars_[index].get().set_progress(value);
    write_progress(os);
  }

  void write_progress(std::ostream &os = std::cout)
  {
    std::unique_lock<std::mutex> lock{mutex_};

    // Move cursor up if needed
    if (started_)
      for (size_t i = 0; i < count; ++i)
        os << "\x1b[A";

    // Write each bar
    for (auto &bar : bars_)
    {
      bar.get().write_progress();
      os << "\n";
    }

    if (!started_)
      started_ = true;
  }

private:
  std::array<std::reference_wrapper<Indicator>, count> bars_;
  std::mutex mutex_;
  std::atomic<bool> started_{false};
};

void Ex0_0()
{
  std::cout << std::endl;
  std::cout << termcolor::bold << termcolor::blue;

  ProgressBar bar;
  bar.set_bar_width(50);
  bar.fill_bar_progress_with("=");
  bar.fill_bar_remainder_with(" ");

  for (size_t i = 1; i <= 100; ++i)
  {
    bar.update(i);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }
  std::cout << std::endl;

  std::cout << termcolor::reset;

  // MultiProgress<ProgressBar, 1> bars(bar);
}

int Ex1_0()
{
  std::cout << termcolor::bold << termcolor::green << "\n\n"
            << std::endl;

  ProgressBar bar1, bar2, bar3;
  MultiProgress<ProgressBar, 3> bars(bar1, bar2, bar3);

  // Job for the first bar
  auto job1 = [&bars]() {
    for (size_t i = 0; i <= 100; ++i)
    {
      bars.update<0>(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  };

  // Job for the second bar
  auto job2 = [&bars]() {
    for (size_t i = 0; i <= 100; ++i)
    {
      bars.update<1>(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
  };

  // Job for the third bar
  auto job3 = [&bars]() {
    for (size_t i = 0; i <= 100; ++i)
    {
      bars.update<2>(i);
      std::this_thread::sleep_for(std::chrono::milliseconds(60));
    }
  };

  std::thread first_job(job1);
  std::thread second_job(job2);
  std::thread third_job(job3);

  first_job.join();
  second_job.join();
  third_job.join();

  std::cout << termcolor::reset << std::endl;

  return 0;
}
} // namespace indicatorstrain
