/* @File  : threadpool.h
 * @Auther: xza
 */
#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <memory>
#include <assert.h>

struct Pool{
    std::mutex mtx;
    std::condition_variable cond;
    bool isClosed;
    std::queue<std::function<void()>> tasks;
};

class ThreadPool{
public:
    explicit ThreadPool(size_t thread_num)
    :_pool(std::make_shared<Pool>()){
        assert(thread_num>0);
        for(size_t i=0; i<thread_num; ++i){
            std::thread([pool = _pool]{
                std::unique_lock<std::mutex> locker(pool->mtx);
                while(true){
                    if(!pool->tasks.empty()){
                        auto task = std::move(pool->tasks.front());
                        pool->tasks.pop();
                        locker.unlock();
                        task();
                        locker.lock();
                    }else if(pool->isClosed){
                        break;
                    }else{
                        pool->cond.wait(locker);
                    }
                }
            }).join();
        }
    }

    ThreadPool() = default;
    ThreadPool(ThreadPool&& ) = default;
    ThreadPool(const ThreadPool&) = delete;
    ~ThreadPool(){
        if(static_cast<bool>(_pool)){
            {
                std::lock_guard<std::mutex> locker(_pool->mtx);
                _pool->isClosed=true;
            }
            _pool->cond.notify_all();
        }
    }

    template<class F>
    void AddTask(F&& task){
        {
            std::lock_guard<std::mutex> locker(_pool->mtx);
            _pool->tasks.emplace(std::forward<F>(task));
        }
        _pool->cond.notify_all();
    }

private:
    std::shared_ptr<Pool> _pool;
};
#endif // THREADPOOL_H_
