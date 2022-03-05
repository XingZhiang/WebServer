/* @File  : config.cpp
 * @Auther: xza
 */

#include "./config.h"

Config::Config(const std::string path){
    this->Load(path);
}

void Config::Load(const std::string path){
    Json::Value root; 
    std::ifstream config_doc(path, std::ifstream::binary);
    config_doc >> root;
    this->port = root.get("port",8080).asUInt64();
    this->thread_num = root.get("thread_num",100).asInt();
    config_doc.close();
}
