/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    smmanagerpluginmodel.h
 * @brief
 *******************************************************************************
 */
#ifndef SMMANAGERPLUGINMODEL_H
#define SMMANAGERPLUGINMODEL_H

#include "plugininterface/plugininterface.h"
#include "smmanagerview.h"
namespace SMManager {
class SMManagerPluginModel : public PluginInterFace
{
    Q_OBJECT
public:
    explicit SMManagerPluginModel(QObject *parent = 0);
    virtual ~SMManagerPluginModel();

    virtual const QString &getPluginName() const;
    virtual void setPluginName(const QString &pluginName);
    virtual QWidget *getWidget() const;
    virtual const QMimeData &getMineData() const;
    virtual void setMimeData(const MIMEDATA_TYPE &mimetype, const QVariant &data);


private:
    SMManagerView *m_widget;
    QString m_pluginName;
};
}
#endif // SMMANAGERPLUGINMODEL_H
