/*
 * This file is part of the SmuView project.
 *
 * Copyright (C) 2018 Frank Stettner <frank-stettner@gmx.net>
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
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include <vector>

#include <QApplication>
#include <QDebug>
#include <QHBoxLayout>
#include <QPushButton>
#include <QVBoxLayout>

#include "demodmmcontrolview.hpp"
#include "src/session.hpp"
#include "src/data/datautil.hpp"
#include "src/devices/hardwaredevice.hpp"
#include "src/widgets/quantitycombobox.hpp"
#include "src/widgets/quantityflagslist.hpp"

using std::vector;

namespace sv {
namespace views {

DemoDMMControlView::DemoDMMControlView(const Session &session,
		shared_ptr<devices::Configurable> configurable, QWidget *parent) :
	BaseView(session, parent),
	configurable_(configurable)
{
	configurable_->list_measured_quantity(measured_quantity_list_);

	setup_ui();
	connect_signals();
	init_values();
}

QString DemoDMMControlView::title() const
{
	return configurable_->name() + " " + tr("Control");
}

void DemoDMMControlView::setup_ui()
{
	QVBoxLayout *layout = new QVBoxLayout();

	// The demo dmm device has no listable measurement quantities /
	// qunatity flags, so we use all...
	quantity_box_ = new widgets::QuantityComboBox();
	layout->addWidget(quantity_box_);
	quantity_flags_list_ = new widgets::QuantityFlagsList();
	layout->addWidget(quantity_flags_list_);

	set_button_ = new QPushButton();
	set_button_->setText(tr("Set"));
	layout->addWidget(set_button_, 0);

	this->centralWidget_->setLayout(layout);
}

void DemoDMMControlView::connect_signals()
{
	// Control elements -> Device
	connect(set_button_, SIGNAL(clicked(bool)), this, SLOT(on_quantity_set()));

	// Device -> control elements
}

void DemoDMMControlView::init_values()
{
}

void DemoDMMControlView::on_quantity_set()
{
	/*
	data::Quantity quantity = quantity_box_->selected_sr_quantity();
	set<data::QuantityFlag> quantity_flags =
		quantity_flags_list_->selected_sr_quantity_flags();

	auto mq_pair = make_pair(quantity, quantity_flags);
	configurable_->set_measured_quantity(mq_pair);
	*/
}

} // namespace views
} // namespace sv

