/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    plugininterface.h
 * @brief
 *******************************************************************************
 */
#ifndef PLUGININTERFACE_H
#define PLUGININTERFACE_H

#include "plugininterface_global.h"
#include <QObject>

class PLUGININTERFACESHARED_EXPORT PluginInterFace : public QObject
{
    Q_OBJECT
public:
    PluginInterFace(QObject *parent=0);
    virtual ~PluginInterFace();
    virtual QString getPluginName() = 0;
    virtual QWidget * getWidget() = 0;

};

#endif // PLUGININTERFACE_H
