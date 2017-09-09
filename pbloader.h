#ifndef PBLOADER_H
#define PBLOADER_H

#include"src_proto/config.pb.h"
#include"src_proto/window.pb.h"

class PBLoader
{
public:
    PBLoader();
    protocol::Config config;
    protocol::Window window;
    bool loadConfig(const std::string& filename,bool binMode=false);
    bool saveConfig(const std::string& filename,bool binMode=false);

    bool loadWindow(const std::string& filename,bool binMode=false);
    bool saveWindow(const std::string& filename,bool binMode=false);
};

#endif // PBLOADER_H
