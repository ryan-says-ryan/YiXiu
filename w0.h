 #ifndef W0_H
#define W0_H

#include <QWidget>

namespace Ui {
class w0;
}

class w0 : public QWidget
{
    Q_OBJECT

public:
    explicit w0(QWidget *parent = nullptr);
    ~w0();

private:
    Ui::w0 *ui;
};

#endif // W0_H
