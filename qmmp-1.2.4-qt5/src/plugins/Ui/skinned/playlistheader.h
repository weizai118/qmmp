/***************************************************************************
 *   Copyright (C) 2015-2016 by Ilya Kotov                                 *
 *   forkotov02@ya.ru                                                      *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/

#ifndef PLAYLISTHEADER_H
#define PLAYLISTHEADER_H

#include <QWidget>
#include <QPixmap>
#include <QList>

class QFontMetrics;
class QFont;
class QMouseEvent;
class QContextMenuEvent;
class QMenu;
class QAction;
class Skin;
class PlayListHeaderModel;

/**
    @author Ilya Kotov <forkotov02@ya.ru>
*/
class PlayListHeader : public QWidget
{
    Q_OBJECT
public:
    explicit PlayListHeader(QWidget *parent = 0);
    ~PlayListHeader();

    void readSettings();
    void setNumberWidth(int width);
    int requiredHeight() const;
    QList<int> sizes() const;
    QList<int> alignment() const;
    int trackStateColumn() const;
    int maxScrollValue() const;
    int offset() const;
    bool hasAutoResizeColumn() const;

public slots:
    void scroll(int offset);
    void updateColumns();
    void showSortIndicator(int column, bool reverted);
    void hideSortIndicator();

private slots:
    void updateSkin();
    void addColumn();
    void editColumn();
    void removeColumn();
    void setAutoResize(bool on);
    void showTrackState(bool on);
    void setAlignment(QAction *action);
    void onColumnAdded(int index);
    void onColumnRemoved();

private:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *e);
    void resizeEvent(QResizeEvent *e);
    void contextMenuEvent(QContextMenuEvent *e);
    void paintEvent(QPaintEvent *);
    void loadColors();
    void adjustColumn(int index);
    int autoResizeColumn() const;
    int findColumn(QPoint pos);
    int size(int index) const;
    void setSize(int index, int size);
    const QString name(int index) const;
    void writeSettings();


    enum DataKey
    {
        NAME = 0,
        SIZE,
        RECT, //geometry
        AUTO_RESIZE,
        TRACK_STATE,
        ALIGNMENT
    };

    Skin *m_skin;
    QFontMetrics *m_metrics;
    QMenu *m_menu, *m_alignmentMenu;
    QFont m_font;
    QColor m_normal, m_normal_bg, m_current;
    QPoint m_pressed_pos;
    QPoint m_mouse_pos;
    PlayListHeaderModel *m_model;
    QAction *m_trackStateAction;
    QAction *m_autoResizeAction;
    QPixmap m_arrow_up, m_arrow_down;
    bool m_reverted;
    bool m_auto_resize;
    int m_number_width;
    int m_pressed_column;
    int m_old_size;
    int m_press_offset;
    int m_padding;
    int m_pl_padding;
    int m_sorting_column;
    int m_offset;


    enum
    {
        NO_TASK = -1,
        RESIZE,
        MOVE,
        SORT
    } m_task;


};

#endif // PLAYLISTHEADER_H
