workspace "V4"
    architecture "x64"
    startproject "V4"

    configurations { "Debug",  "Release"}

    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "Polynomial"
    include "V4"
  



