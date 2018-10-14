MAINTAINERCLEANFILES = Makefile.in

#
# Extra files
#
#EXTRA_DIST = assets
#
##Subdirs; place '.' before any directory to force the current directory to
##be compiled before the subdirs.
#SUBDIRS = assets

#
# Libs
#

#Simple distributable library
#lib_LTLIBRARIES = libmy_lib.la

#Library sources
#libmy_lib_la_SOURCES = 	lib1.c

#Distributable headers
#include_HEADERS = distributable_header.h

#Dependencies
#libmy_lib_la_LIBADD = subdir/libmy_sublib.la

#Library specific CPPFLAGS
#libmy_lib_la_CPPFLAGS = "-ITEST_MACRO"

#
# bin program
#

# Program name
bin_PROGRAMS = 2d_engine_textures

2d_engine_textures_SOURCES = main.cc game.cc texture_manager.cc game_object.cc \
				map.cc
2d_engine_textures_LDADD = -lSDL2 -lSDL2_image

#You can also tweak CFLAGS, CXXFLAGS and CPPFLAGS
