#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsTextItem>
#include <QObject>

class GraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    GraphicsView(QGraphicsScene *scene);
    void zoomAll();
    QRectF visibleArea() const;
protected:
    void resizeEvent(QResizeEvent *event) override;
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void drawForeground(QPainter *painter, const QRectF &rect) override;
private:
    // Console
    QFont m_font;
    QColor m_color;
};

#endif // GRAPHICSVIEW_H
