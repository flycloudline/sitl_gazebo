/*
 * Copyright (C) 2014 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include <sstream>
#include <gazebo/msgs/msgs.hh>
#include "Int32.pb.h"
#include "gazebo_overlay_widget.h"
#include "overlay.h"

using namespace gazebo;

// Register this plugin with the simulator
GZ_REGISTER_GUI_PLUGIN(OverlayWidget)

/////////////////////////////////////////////////
OverlayWidget::OverlayWidget()
  : GUIPlugin()
{
  this->counter = 0;

  // Set the frame background and foreground colors
  this->setStyleSheet(
      "QFrame#ImageFrame { background-color : rgba(100, 100, 100, 255); color : white; }");

  // Create the main layout
  QHBoxLayout *mainLayout = new QHBoxLayout;

  // Create the frame to hold all the widgets
  QFrame *mainFrame = new QFrame();

  // Create the layout that sits inside the frame
  QVBoxLayout *frameLayout = new QVBoxLayout();

  mainFrame->setLayout(frameLayout);

  // Add the frame to the main layout
  mainLayout->addWidget(mainFrame);

  // Remove margins to reduce space
  frameLayout->setContentsMargins(0, 0, 0, 0);
  mainLayout->setContentsMargins(0, 0, 0, 0);

  this->setLayout(mainLayout);

  // Position and resize this widget
  this->resize(60, 60);
  this->move(10, 10);

  image1.loadFromData(Auterion::auterionlogo, sizeof(Auterion::auterionlogo));

  image1 = image1.scaled(60, 60, Qt::KeepAspectRatio, Qt::SmoothTransformation);
}

/////////////////////////////////////////////////
OverlayWidget::~OverlayWidget()
{
}

void OverlayWidget::paintEvent(QPaintEvent * /*e*/)
{
  QPainter* p = new QPainter(this);
  p->drawPixmap(0, 0, image1);
  delete p;
}