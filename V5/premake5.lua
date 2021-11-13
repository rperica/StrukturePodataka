workspace "V5"
    architecture "x64"
    startproject "V5"

    configurations { "Debug",  "Release"}

    outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    include "Stack"
    include "V5"
  



