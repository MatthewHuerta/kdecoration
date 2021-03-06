/*
 * Copyright 2014  Martin Gräßlin <mgraesslin@kde.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef MOCK_DECORATION_H
#define MOCK_DECORATION_H

#include "../src/decoration.h"

class MockBridge;

class MockDecoration : public KDecoration2::Decoration
{
    Q_OBJECT
public:
    explicit MockDecoration(QObject *parent, const QVariantList &args);
    explicit MockDecoration(MockBridge *bridge);
    void paint(QPainter *painter, const QRect &repaintRegion) override;
    void setOpaque(bool set);
    using Decoration::setBorders;
    void setBorders(const QMargins &m);
    using Decoration::setTitleBar;
    void setTitleBar(const QRect &rect);
};

#endif
