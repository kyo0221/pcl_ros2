#ifndef PCL_ROS2__VISIBILITY_CONTROL_H_
#define PCL_ROS2__VISIBILITY_CONTROL_H_

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define PCL_ROS2_EXPORT __attribute__ ((dllexport))
    #define PCL_ROS2_IMPORT __attribute__ ((dllimport))
  #else
    #define PCL_ROS2_EXPORT __declspec(dllexport)
    #define PCL_ROS2_IMPORT __declspec(dllimport)
  #endif
  #ifdef PCL_ROS2_BUILDING_LIBRARY
    #define PCL_ROS2_PUBLIC PCL_ROS2_EXPORT
  #else
    #define PCL_ROS2_PUBLIC PCL_ROS2_IMPORT
  #endif
  #define PCL_ROS2_PUBLIC_TYPE PCL_ROS2_PUBLIC
  #define PCL_ROS2_LOCAL
#else
  #define PCL_ROS2_EXPORT __attribute__ ((visibility("default")))
  #define PCL_ROS2_IMPORT
  #if __GNUC__ >= 4
    #define PCL_ROS2_PUBLIC __attribute__ ((visibility("default")))
    #define PCL_ROS2_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define PCL_ROS2_PUBLIC
    #define PCL_ROS2_LOCAL
  #endif
  #define PCL_ROS2_PUBLIC_TYPE
#endif

#endif  // PCL_ROS2__VISIBILITY_CONTROL_H_
