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

    virtual QString getPluginName();
    virtual QWidget * getWidget();

private:
    SMManagerView *m_widget;
};
}
#endif // SMMANAGERPLUGINMODEL_H
