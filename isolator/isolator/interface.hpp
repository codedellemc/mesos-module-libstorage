#ifndef __INTERFACE_HPP__
#define __INTERFACE_HPP__

#include <isolator/interface.pb.h>
using namespace emccode::isolator::mount;

#include <stout/multihashmap.hpp>

class Builder
{
private:
  // variables needed for construction of ExternalMount
  std::string containerId;
  std::string volumeDriver;
  std::string volumeName;
  std::string mountPoint;
  //hashmap<std::string, std::string> opts; //TODO revisit this later
  std::string options;
  std::string containerPath;

public:
  // create Builder with default values assigned
  // (in C++11 they can be simply assigned above on declaration instead)
  Builder() {}

  // sets custom values for Product creation
  // returns Builder for shorthand inline usage (same way as cout <<)
  Builder& setContainerId( const std::string containerId )
  {
    this->containerId = containerId;
    return *this;
  }
  Builder& setVolumeDriver( const std::string volumeDriver )
  {
    this->volumeDriver = volumeDriver;
    return *this;
  }
  Builder& setVolumeName( const std::string volumeName )
  {
    this->volumeName = volumeName;
    return *this;
  }
  Builder& setMountPoint( const std::string mountPoint )
  {
    this->mountPoint = mountPoint;
    return *this;
  }
  //TODO revisit this later
  /*
  Builder& addOption( const std::string key, const std::string value )
  {
    this->opts.put( key, value );
    return *this;
  }
  */
  Builder& setOptions( const std::string options )
  {
    this->options = options;
    return *this;
  }

  Builder& setContainerPath( const std::string _containerPath )
  {
    this->containerPath = _containerPath;
    return *this;
  }

  ExternalMount* build()
  {
    ExternalMount* mount = new ExternalMount();
    mount->set_containerid(containerId);
    mount->set_volumedriver(volumeDriver);
    mount->set_volumename(volumeName);
    mount->set_mountpoint(mountPoint);
    mount->set_options(options);
    mount->set_container_path(containerPath);

    //TODO revisit this later
    /*
    for (const auto &opt : opts)
    {
      ExternalMount_ExternalMountOption* newopt = mount->add_option();
      newopt->set_key(opt.first);
      newopt->set_key(opt.second);
    }
    */

    return mount;
  }
};

#endif //#ifndef __INTERFACE_HPP__
