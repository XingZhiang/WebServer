/* @File   :config
 * @Auther :xza
 */
#ifndef CONFIG_H
#define CONFIG_H

#include <json/json.h>
#include <fstream>
#include <string>

class Config{
public:
    Config(const std::string path);
    Config()=default;
    Config(Config&&)=default;
    void Load(const std::string path);

public:
    uint16_t port;
    size_t thread_num;
};


#endif // CONFIG_H
