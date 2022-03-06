/* @File    :buffer.h
 * @Auther  :xza
 */
#ifndef BUFFER_H
#define BUFFER_H

#include <string>
#include <iostream>
#include <atomic>
#include <assert.h>
#include <fstream>

class Buffer{
    Buffer(std::size_t init_buffer_size=1024);
    ~Buffer()=default;

    size_t WriteableBytesSize() const;
    size_t ReadableBytesSize() const;
    size_t PrependableBytesSize() const;

    void Append(const std::string& str);
    void Append(const char* str, size_t len);
    void Append(const void* data, size_t len);
    void Append(const Buffer& buff);

    std::size_t ReadFile();
    std::size_t WriteFile();

private:
    
    std::string _buffer;
    std::atomic<std::size_t> _read_pos;
    std::atomic<std::size_t> _write_pos;
};




#endif //BUFFER_H
