#include "pbloader.h"
#include <fstream>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
using namespace std;
using namespace google::protobuf;
PBLoader::PBLoader()
{
    config.set_version("1.0");
 /*
    protocol::Obj2dString* o=config.add_labels();
    o->set_name("label1");
    o->set_text("text1");
    o->set_x(1.0);
    o->set_y(1.0);
    o->set_rad(0.0);
    */
}

bool PBLoader::loadConfig(const std::string& filename,bool binMode){
    protocol::Config config;
    if(binMode){
        ifstream ifs(filename,ios::binary);
        if(!ifs.is_open()){
            // file not found
            return false;
        }else if(!config.ParseFromIstream(&ifs)){
            // format error
            return false;
        }
    }else{
        ifstream ifs(filename);
        TextFormat::Parser parser;
        if(!ifs.is_open()){
            // file not found
            return false;
        }else{
            io::IstreamInputStream iss(&ifs);
            if(!parser.Parse(&iss,&config)){
                // format error
                return false;
            }

        }
    }
    this->config.MergeFrom(config);
    return true;
}

bool PBLoader::saveConfig(const std::string& filename,bool binMode){
    if(binMode){
        ofstream ofs(filename,ios::trunc|ios::binary);
        if(!ofs){
            // file not found
            return false;
        }else if(!config.SerializeToOstream(&ofs)){
            // format error
            return false;
        }
    }else{
        ofstream ofs(filename,ios::trunc);
        if(!ofs){
            // file not found
            return false;
        }
        io::OstreamOutputStream oss(&ofs);
        if(!TextFormat::Print(config,&oss)){
            return false;
        }
    }
    return true;
}

bool PBLoader::loadWindow(const std::string& filename,bool binMode){
    if(binMode){
        ofstream ofs(filename,ios::trunc|ios::binary);
        if(!ofs){
            // file not found
            return false;
        }else if(!window.SerializeToOstream(&ofs)){
            // format error
            return false;
        }
    }else{
        ofstream ofs(filename,ios::trunc);
        if(!ofs){
            // file not found
            return false;
        }
        io::OstreamOutputStream oss(&ofs);
        if(!TextFormat::Print(window,&oss)){
            return false;
        }
    }
    return true;
}

bool PBLoader::saveWindow(const std::string& filename,bool binMode){
    if(binMode){
        ofstream ofs(filename,ios::trunc|ios::binary);
        if(!ofs){
            // file not found
            return false;
        }else if(!window.SerializeToOstream(&ofs)){
            // format error
            return false;
        }
    }else{
        ofstream ofs(filename,ios::trunc);
        if(!ofs){
            // file not found
            return false;
        }
        io::OstreamOutputStream oss(&ofs);
        if(!TextFormat::Print(window,&oss)){
            return false;
        }
    }
    return true;
}
