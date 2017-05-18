/**
 *******************************************************************************
 *                       Continental Confidential
 *                  Copyright (c) Continental AG. 2017
 *
 *      This software is furnished under license and may be used or
 *      copied only in accordance with the terms of such license.
 *******************************************************************************
 * @file    graphicsview.h
 * @brief
 *******************************************************************************
 */
#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsPathItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPointF>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    GraphicsScene(QObject *parent = Q_NULLPTR);
    virtual ~GraphicsScene() = default;

};


class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    GraphicsView(QWidget *parent = Q_NULLPTR);
    virtual ~GraphicsView();
    void setPoints(const QVector<QPointF> &points);
    void setPixmap(const QPixmap &pic);

protected:
    QVector<QPointF> m_points;
    GraphicsScene    *m_scene;
    QGraphicsPathItem *m_pathItem;
    QGraphicsPixmapItem *m_pixmapItem;
};

#endif // GRAPHICSVIEW_H
