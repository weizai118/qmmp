#Common settings for Qmmp build

#Extra clean target

unix: QMAKE_DISTCLEAN += -r .build

#Some conf to redirect intermediate stuff in separate dirs

UI_DIR=./.build/ui/
MOC_DIR=./.build/moc/
OBJECTS_DIR=./.build/obj
RCC_DIR=./.build/rcc

#Defines

DEFINES += QT_NO_CAST_FROM_BYTEARRAY QT_STRICT_ITERATORS

#Version

QMMP_VERSION = 0.11.3

#Include and link paths
win32 {
QMAKE_CFLAGS_ISYSTEM = -isystem
EXTRA_INCDIR = C:/devel/mingw32-libs/include
QMAKE_CXXFLAGS += "$${QMAKE_CFLAGS_ISYSTEM} $${EXTRA_INCDIR}"
QMAKE_CFLAGS += "$${QMAKE_CFLAGS_ISYSTEM} $${EXTRA_INCDIR}"
QMAKE_LIBDIR +=  C:/devel/mingw32-libs/lib
}

#Comment/uncomment this if you want to change plugins list

CONFIG += ARCHIVE_PLUGIN
CONFIG += JACK_PLUGIN
CONFIG += FLAC_PLUGIN
CONFIG += MUSEPACK_PLUGIN
CONFIG += FFMPEG_PLUGIN
CONFIG += MODPLUG_PLUGIN
CONFIG += WILDMIDI_PLUGIN
CONFIG += GME_PLUGIN
CONFIG += OPUS_PLUGIN
CONFIG += OSS_PLUGIN #deprecated
CONFIG += PULSE_AUDIO_PLUGIN
CONFIG += ALSA_PLUGIN
#CONFIG += OSS4_PLUGIN
CONFIG += AAC_PLUGIN
CONFIG += MPLAYER_PLUGIN
CONFIG += CDAUDIO_PLUGIN
CONFIG += BS2B_PLUGIN
CONFIG += SOXR_PLUGIN
CONFIG += LADSPA_PLUGIN
CONFIG += FILEWRITER_PLUGIN
CONFIG += PROJECTM_PLUGIN
CONFIG += UDISKS_PLUGIN #deprecated
CONFIG += UDISKS2_PLUGIN
CONFIG += HAL_PLUGIN
CONFIG += SID_PLUGIN
CONFIG += QTMULTIMEDIA_PLUGIN
CONFIG += SHOUT_PLUGIN

#additional features

CONFIG += WITH_ENCA
CONFIG += WITH_PROJECTM20
CONFIG += WITH_SKINNED
CONFIG += WITH_QSUI
CONFIG += WITH_NEW_JACK
#CONFIG += FFMPEG_LEGACY #uncomment for ffmpeg < 0.9 or libav < 0.8

CONFIG -= $$DISABLED_PLUGINS
