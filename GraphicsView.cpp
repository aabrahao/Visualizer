#include "GraphicsView.h"
#include "Logger.h"

GraphicsView::GraphicsView(QGraphicsScene *scene)
    : QGraphicsView(scene),
      m_font("Monospace", 2),
      m_color(255, 255, 255, 128) {
    setBackgroundBrush(QColor(48, 48, 48));
}

void GraphicsView::zoomAll() {
    fitInView(sceneRect(), Qt::KeepAspectRatio);
}

void GraphicsView::resizeEvent(QResizeEvent *event) {
    zoomAll();
}
void GraphicsView::drawBackground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawBackground(painter, rect);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::black);
    qreal s = 0.05*rect.height();
    painter->drawLine(-s, 0, s, 0);
    painter->drawLine(0, -s, 0, s);
    s /= 2;
    painter->drawEllipse(-0.5*s, -0.5*s, s, s);
}

void GraphicsView::drawForeground(QPainter *painter, const QRectF &rect) {
    QGraphicsView::drawForeground(painter, rect);
    painter->setPen(m_color);
    painter->setBrush(m_color);
    painter->setFont(m_font);
    painter->drawText(rect, logger().messages());
}

QRectF GraphicsView::visibleArea() const {
    QPointF top = mapToScene (0, 0);
    QPointF bottom = mapToScene (width(), height());
    return QRectF (top, bottom);
}
