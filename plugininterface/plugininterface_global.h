/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    plugininterface_global.h
 * @brief
 *******************************************************************************
 */
#ifndef PLUGININTERFACE_GLOBAL_H
#define PLUGININTERFACE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PLUGININTERFACE_LIBRARY)
#  define PLUGININTERFACESHARED_EXPORT Q_DECL_EXPORT
#else
#  define PLUGININTERFACESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PLUGININTERFACE_GLOBAL_H
