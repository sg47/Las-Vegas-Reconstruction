/* Copyright (C) 2011 Uni Osnabrück
 * This file is part of the LAS VEGAS Reconstruction Toolkit,
 *
 * LAS VEGAS is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * LAS VEGAS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA
 */

/**
 * LVRCorrespondanceDialog.hpp
 *
 *  @date Feb 18, 2014
 *  @author Thomas Wiemann
 */
#ifndef LVRCORRESPONDANCEDIALOG_HPP_
#define LVRCORRESPONDANCEDIALOG_HPP_

#include "LVRRegistrationPickCorrespondancesDialogUI.h"
#include "../vtkBridge/LVRVtkArrow.hpp"

#include "geometry/Matrix4.hpp"
#include "registration/EigenSVDPointAlign.hpp"

#include <iostream>
using namespace std;

namespace lvr
{

class LVRCorrespondanceDialog : public QObject
{
    Q_OBJECT
public:
    LVRCorrespondanceDialog(QTreeWidget* parent);
    virtual ~LVRCorrespondanceDialog();
    void fillComboBoxes();
    Matrix4f getTransformation();
    QString  getModelName();
    QString  getDataName();

    bool    doICP();
    double  getEpsilon();
    double  getMaxDistance();
    int     getMaxIterations();

public Q_SLOTS:
    void updateModelSelection(int);
    void updateDataSelection(int);
    void firstPointPicked(double*);
    void secondPointPicked(double*);
    void insertNewItem();
    void deleteItem();
    void swapItemPositions();
    void saveCorrespondences();
    void loadCorrespondences();
    void treeItemSelected(QTreeWidgetItem*, QTreeWidgetItem*);
    void clearAllItems();


Q_SIGNALS:
    void render();
    void removeArrow(LVRVtkArrow *);
    void addArrow(LVRVtkArrow *);
    void disableCorrespondenceSearch();
    void enableCorrespondenceSearch();

public:
    Ui_CorrespondenceDialog*    m_ui;
    QDialog*                    m_dialog;

private:
    QTreeWidget*                m_treeWidget;
    QColor                      m_dataSelectionColor;
    QColor                      m_modelSelectionColor;
    QColor                      m_defaultColor;
    QString                     m_dataSelection;
    QString                     m_modelSelection;
};

} /* namespace lvr */

#endif /* LVRCORRESPONDANCEDIALOG_HPP_ */
