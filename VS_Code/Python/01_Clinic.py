from typing_extensions import Self
from PyQt5 import QtCore, QtGui, QtWidgets
import datetime as dt
from logging import PlaceHolder


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1114, 740)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(20, 0, 1071, 61))
        font = QtGui.QFont()
        font.setFamily("3ds")
        font.setPointSize(18)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.calendarWidget = QtWidgets.QCalendarWidget(self.centralwidget)
        self.calendarWidget.setGeometry(QtCore.QRect(770, 70, 321, 201))
        self.calendarWidget.setObjectName("calendarWidget")
        self.groupBox = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox.setGeometry(QtCore.QRect(20, 60, 701, 201))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.groupBox.setFont(font)
        self.groupBox.setObjectName("groupBox")
        self.widget = QtWidgets.QWidget(self.groupBox)
        self.widget.setGeometry(QtCore.QRect(10, 140, 311, 48))
        self.widget.setObjectName("widget")
        self.formLayout_3 = QtWidgets.QFormLayout(self.widget)
        self.formLayout_3.setContentsMargins(0, 0, 0, 0)
        self.formLayout_3.setObjectName("formLayout_3")
        self.p_num_label = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.p_num_label.setFont(font)
        self.p_num_label.setObjectName("p_num_label")
        self.formLayout_3.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.p_num_label)
        self.lineEdit_pNum = QtWidgets.QLineEdit(self.widget)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_pNum.setFont(font)
        self.lineEdit_pNum.setObjectName("lineEdit_pNum")
        self.formLayout_3.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.lineEdit_pNum)
        self.email_label = QtWidgets.QLabel(self.widget)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.email_label.setFont(font)
        self.email_label.setObjectName("email_label")
        self.formLayout_3.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.email_label)
        self.lineEdit_email = QtWidgets.QLineEdit(self.widget)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_email.setFont(font)
        self.lineEdit_email.setObjectName("lineEdit_email")
        self.formLayout_3.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.lineEdit_email)
        self.widget1 = QtWidgets.QWidget(self.groupBox)
        self.widget1.setGeometry(QtCore.QRect(10, 80, 681, 48))
        self.widget1.setObjectName("widget1")
        self.formLayout_2 = QtWidgets.QFormLayout(self.widget1)
        self.formLayout_2.setContentsMargins(0, 0, 0, 0)
        self.formLayout_2.setObjectName("formLayout_2")
        self.address_line1_label = QtWidgets.QLabel(self.widget1)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.address_line1_label.setFont(font)
        self.address_line1_label.setObjectName("address_line1_label")
        self.formLayout_2.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.address_line1_label)
        self.lineEdit_address_line1 = QtWidgets.QLineEdit(self.widget1)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_address_line1.setFont(font)
        self.lineEdit_address_line1.setObjectName("lineEdit_address_line1")
        self.formLayout_2.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.lineEdit_address_line1)
        self.address_line2_label = QtWidgets.QLabel(self.widget1)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.address_line2_label.setFont(font)
        self.address_line2_label.setObjectName("address_line2_label")
        self.formLayout_2.setWidget(1, QtWidgets.QFormLayout.LabelRole, self.address_line2_label)
        self.lineEdit_address_line2 = QtWidgets.QLineEdit(self.widget1)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_address_line2.setFont(font)
        self.lineEdit_address_line2.setObjectName("lineEdit_address_line2")
        self.formLayout_2.setWidget(1, QtWidgets.QFormLayout.FieldRole, self.lineEdit_address_line2)
        self.widget2 = QtWidgets.QWidget(self.groupBox)
        self.widget2.setGeometry(QtCore.QRect(10, 20, 681, 48))
        self.widget2.setObjectName("widget2")
        self.gridLayout = QtWidgets.QGridLayout(self.widget2)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.f_name_label = QtWidgets.QLabel(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.f_name_label.setFont(font)
        self.f_name_label.setObjectName("f_name_label")
        self.gridLayout.addWidget(self.f_name_label, 0, 0, 1, 1)
        self.lineEdit_f_name = QtWidgets.QLineEdit(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_f_name.setFont(font)
        self.lineEdit_f_name.setObjectName("lineEdit_f_name")
        self.gridLayout.addWidget(self.lineEdit_f_name, 0, 1, 1, 1)
        self.DOB_label = QtWidgets.QLabel(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.DOB_label.setFont(font)
        self.DOB_label.setObjectName("DOB_label")
        self.gridLayout.addWidget(self.DOB_label, 0, 2, 1, 1)
        self.dob_Edit = QtWidgets.QDateEdit(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.dob_Edit.setFont(font)
        self.dob_Edit.setObjectName("dob_Edit")
        self.gridLayout.addWidget(self.dob_Edit, 0, 3, 1, 1)
        self.l_name_label = QtWidgets.QLabel(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.l_name_label.setFont(font)
        self.l_name_label.setObjectName("l_name_label")
        self.gridLayout.addWidget(self.l_name_label, 1, 0, 1, 1)
        self.lineEdit_l_name = QtWidgets.QLineEdit(self.widget2)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.lineEdit_l_name.setFont(font)
        self.lineEdit_l_name.setObjectName("lineEdit_l_name")
        self.gridLayout.addWidget(self.lineEdit_l_name, 1, 1, 1, 1)
        self.pushButton_submit = QtWidgets.QPushButton(self.groupBox, clicked = lambda: self.submit_it())
        self.pushButton_submit.setGeometry(QtCore.QRect(550, 140, 141, 51))
        font = QtGui.QFont()
        font.setFamily("3ds")
        font.setPointSize(16)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_submit.setFont(font)
        self.pushButton_submit.setObjectName("pushButton_submit")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(20, 280, 1071, 431))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.groupBox_2.setFont(font)
        self.groupBox_2.setObjectName("groupBox_2")
        self.pushButton_schedule = QtWidgets.QPushButton(self.groupBox_2)
        self.pushButton_schedule.setGeometry(QtCore.QRect(100, 360, 251, 61))
        font = QtGui.QFont()
        font.setFamily("3ds")
        font.setPointSize(16)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_schedule.setFont(font)
        self.pushButton_schedule.setObjectName("pushButton_schedule")
        self.table_Apt = QtWidgets.QTableView(self.groupBox_2)
        self.table_Apt.setGeometry(QtCore.QRect(480, 40, 581, 381))
        self.table_Apt.setObjectName("table_Apt")
        self.Table_hdr_label = QtWidgets.QLabel(self.groupBox_2)
        self.Table_hdr_label.setGeometry(QtCore.QRect(480, 20, 341, 16))
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.Table_hdr_label.setFont(font)
        self.Table_hdr_label.setObjectName("Table_hdr_label")
        self.widget3 = QtWidgets.QWidget(self.groupBox_2)
        self.widget3.setGeometry(QtCore.QRect(10, 30, 251, 22))
        self.widget3.setObjectName("widget3")
        self.formLayout_4 = QtWidgets.QFormLayout(self.widget3)
        self.formLayout_4.setContentsMargins(0, 0, 0, 0)
        self.formLayout_4.setObjectName("formLayout_4")
        self.city_label = QtWidgets.QLabel(self.widget3)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.city_label.setFont(font)
        self.city_label.setObjectName("city_label")
        self.formLayout_4.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.city_label)
        self.comboBox_city = QtWidgets.QComboBox(self.widget3)
        self.comboBox_city.setCurrentText("")
        self.comboBox_city.setObjectName("comboBox_city")
        self.formLayout_4.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.comboBox_city)
        self.widget4 = QtWidgets.QWidget(self.groupBox_2)
        self.widget4.setGeometry(QtCore.QRect(10, 70, 361, 22))
        self.widget4.setObjectName("widget4")
        self.horizontalLayout = QtWidgets.QHBoxLayout(self.widget4)
        self.horizontalLayout.setContentsMargins(0, 0, 0, 0)
        self.horizontalLayout.setObjectName("horizontalLayout")
        self.department_label = QtWidgets.QLabel(self.widget4)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.department_label.setFont(font)
        self.department_label.setObjectName("department_label")
        self.horizontalLayout.addWidget(self.department_label)
        self.comboBox_department = QtWidgets.QComboBox(self.widget4)
        self.comboBox_department.setCurrentText("")
        self.comboBox_department.setObjectName("comboBox_department")
        self.horizontalLayout.addWidget(self.comboBox_department)
        self.widget5 = QtWidgets.QWidget(self.groupBox_2)
        self.widget5.setGeometry(QtCore.QRect(10, 110, 231, 22))
        self.widget5.setObjectName("widget5")
        self.formLayout_5 = QtWidgets.QFormLayout(self.widget5)
        self.formLayout_5.setContentsMargins(0, 0, 0, 0)
        self.formLayout_5.setObjectName("formLayout_5")
        self.appointment_label = QtWidgets.QLabel(self.widget5)
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.appointment_label.setFont(font)
        self.appointment_label.setObjectName("appointment_label")
        self.formLayout_5.setWidget(0, QtWidgets.QFormLayout.LabelRole, self.appointment_label)
        self.comboBox_AptType = QtWidgets.QComboBox(self.widget5)
        self.comboBox_AptType.setCurrentText("")
        self.comboBox_AptType.setObjectName("comboBox_AptType")
        self.formLayout_5.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.comboBox_AptType)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def submit_it(self):
        format = "%d/%m/%Y"
        DOB = str(self.dob_Edit.text())
        try:
            dt.datetime.strptime(DOB, format)
            self.Table_hdr_label.setText("You have successfuly filled the form!")
        except ValueError:
            self.Table_hdr_label.setText(f'Please enter the correct date format! ,{DOB}')
            # new = patientInfo(self.lineEdit_f_name.text(),self.lineEdit_l_name.text(), self.dob.text(), self.lineEdit_address_line1.text(), self.lineEdit_address_line2.text(), self.lineEdit_city_comboBox.currentText(), self.lineEdit_department_comboBox.currentText(), self.lineEdit_pNum.text(), self.lineEdit_email.text(), self.lineEdit_apt_Type.text())
            # patients.append(new)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Appointment scheduler for the clinic"))
        self.label.setText(_translate("MainWindow", "Welcome to the appointment scheduler for the clinic, please enter the following information:"))
        self.groupBox.setTitle(_translate("MainWindow", "Personal details"))
        self.p_num_label.setText(_translate("MainWindow", "Phone number:"))
        self.email_label.setText(_translate("MainWindow", "Email: "))
        self.address_line1_label.setText(_translate("MainWindow", "Address line 1:"))
        self.address_line2_label.setText(_translate("MainWindow", "Address line 2:"))
        self.f_name_label.setText(_translate("MainWindow", "First Name (given name):"))
        self.DOB_label.setText(_translate("MainWindow", "Date of birth (DD/MM/YYYY):"))
        self.dob_Edit.setDisplayFormat(_translate("MainWindow", "d/M/yyyy"))
        self.l_name_label.setText(_translate("MainWindow", "Last Name (surname):"))
        self.pushButton_submit.setText(_translate("MainWindow", "Submit"))
        self.groupBox_2.setTitle(_translate("MainWindow", "Appointment details"))
        self.pushButton_schedule.setText(_translate("MainWindow", "Schedule Appointment"))
        self.Table_hdr_label.setText(_translate("MainWindow", "Please choose among the available dates and timings:"))
        self.city_label.setText(_translate("MainWindow", "Pick city from the list:"))
        self.comboBox_city.setPlaceholderText(_translate("MainWindow", "Please select:"))
        self.department_label.setText(_translate("MainWindow", "Choose the department you want to visit:"))
        self.comboBox_department.setPlaceholderText(_translate("MainWindow", "Please select:"))
        self.appointment_label.setText(_translate("MainWindow", "Appointment type:"))
        self.comboBox_AptType.setPlaceholderText(_translate("MainWindow", "Please select:"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
