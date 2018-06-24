#include "window.h"

#include <QMessageBox>

Window::Window()
    : QWidget(nullptr)
{
    ui.setupUi(this);
}

void Window::showErrorMessage(char *msg) const
{
    QMessageBox errorMsg;
    errorMsg.critical(0, "Error", msg);
    errorMsg.setFixedSize(500, 200);
}

void Window::on_btnRotate_clicked()
{
    // Get info from the textboxes
    bool ok1, ok2, ok3;
    double xDeg = ui.txtX->text().toDouble(&ok1);
    double yDeg = ui.txtY->text().toDouble(&ok2);
    double zDeg = ui.txtZ->text().toDouble(&ok3);
    // If some data couldn't be converted to double, show error message and do nothing
    if (!(ok1 && ok2 && ok3))
    {
        showErrorMessage("Error with the format of the data.");
        return;
    }
    // Rotate the shape and repaint the widget
    ui.renderArea->rotateShape(xDeg, yDeg, zDeg);
    ui.renderArea->update();
}

void Window::on_btnScale_clicked()
{
    // Get ratio
    bool ok;
    double ratio = ui.txtScale->text().toDouble(&ok);
    // If the field doesn't contain a double, show error message and do nothing
    if (!ok)
    {
        showErrorMessage("Error with the format of the data.");
        return;
    }
    // Scale the shape and repaint the widget
    ui.renderArea->scaleShape(ratio);
    ui.renderArea->update();
}
