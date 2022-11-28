#ifndef LOG_H
#define LOG_H

#include <iomanip>
#include <iostream>
#include <mutex>

#define syncout LogInfo()
#define syncerr LogError()
#define syncend std::endl

static std::mutex io_mutex;

class Log {
public:
    using Manipulator = std::ostream& (*)(std::ostream&);

    template<typename T>
    Log& operator<<(const T& _t) {
        *os_ << _t;
        return *this;
    }

    Log& operator<<(Manipulator fp) {
        *os_ << fp;
        return *this;
    }

protected:
    Log(std::ostream *os) {
        os_ = os;
        io_lock_ = std::unique_lock<std::mutex>(io_mutex);
    }
    virtual ~Log() = default;

private:
    std::ostream *os_ = nullptr;
    std::unique_lock<std::mutex> io_lock_;
};

class LogInfo: public Log {
public:
    LogInfo() : Log(&std::cout) {}
    virtual ~LogInfo() = default;
};

class LogError: public Log {
public:
    LogError() : Log(&std::cerr) {}
    virtual ~LogError() = default;
};

#endif // LOG_H
