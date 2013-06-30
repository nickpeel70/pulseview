/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 USA
 */

#ifndef PULSEVIEW_PV_VIEW_HEADER_H
#define PULSEVIEW_PV_VIEW_HEADER_H

#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>

#include <list>
#include <utility>

#include "marginwidget.h"

namespace pv {
namespace view {

class Trace;
class View;

class Header : public MarginWidget
{
	Q_OBJECT

public:
	Header(View &parent);

private:
	boost::shared_ptr<pv::view::Trace> get_mouse_over_trace(
		const QPoint &pt);

	void clear_selection();

private:
	void paintEvent(QPaintEvent *event);

private:
	void mousePressEvent(QMouseEvent * event);

	void mouseReleaseEvent(QMouseEvent *event);

	void mouseMoveEvent(QMouseEvent *event);

	void leaveEvent(QEvent *event);

	void contextMenuEvent(QContextMenuEvent *event);

private slots:
	void on_signals_changed();

	void on_action_set_name_triggered();

	void on_action_set_colour_triggered();

	void on_signals_moved();

signals:
	void signals_moved();

private:
	QPoint _mouse_point;
	QPoint _mouse_down_point;

	std::list<std::pair<boost::weak_ptr<Trace>, int> >
		_drag_traces;

	boost::shared_ptr<Trace> _context_trace;
	QAction *_action_set_name;
	QAction *_action_set_colour;
};

} // namespace view
} // namespace pv

#endif // PULSEVIEW_PV_VIEW_HEADER_H
