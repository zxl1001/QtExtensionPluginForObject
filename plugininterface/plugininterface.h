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
#include <QMimeData>

#define MIMEDATA_BYTEARRAY_STRING "bytearray"
#define MIMEDATA_TEXT_STRING "text/plain"
#define MIMEDATA_HTML_STRING "text/html"
#define MIMEDATA_URL_STRING "text/uri-list"
#define MIMEDATA_IMAGE_STRING "image/ *"
#define MIMEDATA_COLOR_STRING "application/x-color"


enum class MIMEDATA_TYPE: uint
{
    MIMEDATA_BYTEARRAY=100,
    MIMEDATA_TEXT,
    MIMEDATA_HTML,
    MIMEDATA_URL,
    MIMEDATA_IMAGE,
    MIMEDATA_COLOR
};

class PLUGININTERFACESHARED_EXPORT PluginInterFace : public QObject
{
    Q_OBJECT
public:
    PluginInterFace(QObject *parent=0);
    virtual ~PluginInterFace();
    virtual const QString &getPluginName() const = 0;
    virtual void setPluginName(const QString &pluginName) = 0;
    virtual QWidget * getWidget() const = 0;
    virtual const QMimeData &getMineData() const = 0;
    virtual void setMimeData(const MIMEDATA_TYPE &mimetype, const QVariant &data) = 0;

protected:
    QMimeData m_mineData;
    QString m_pluginName;

};

#endif // PLUGININTERFACE_H
