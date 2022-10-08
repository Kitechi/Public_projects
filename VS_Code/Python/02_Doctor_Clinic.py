# Camila Cruz
# TEC-322 Working Logic
# ClinicSync

# This enables the code to record patient info
import re


from PyQt5 import QtCore, QtGui, QtWidgets


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
        self.pushButton_validate = QtWidgets.QPushButton(self.groupBox, clicked = lambda: self.validate_it())
        self.pushButton_validate.setGeometry(QtCore.QRect(550, 140, 141, 51))
        font = QtGui.QFont()
        font.setFamily("3ds")
        font.setPointSize(16)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_validate.setFont(font)
        self.pushButton_validate.setObjectName("pushButton_validate")
        self.label_validate = QtWidgets.QLabel(self.groupBox)
        self.label_validate.setGeometry(QtCore.QRect(340, 140, 201, 51))
        self.label_validate.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.label_validate.setAlignment(QtCore.Qt.AlignCenter)
        self.label_validate.setObjectName("label_validate")
        self.groupBox_2 = QtWidgets.QGroupBox(self.centralwidget)
        self.groupBox_2.setGeometry(QtCore.QRect(20, 280, 1071, 431))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.groupBox_2.setFont(font)
        self.groupBox_2.setObjectName("groupBox_2")
        self.pushButton_schedule = QtWidgets.QPushButton(self.groupBox_2, clicked = lambda: self.schedule_it())
        self.pushButton_schedule.setGeometry(QtCore.QRect(100, 350, 251, 61))
        font = QtGui.QFont()
        font.setFamily("3ds")
        font.setPointSize(16)
        font.setBold(False)
        font.setWeight(50)
        self.pushButton_schedule.setFont(font)
        self.pushButton_schedule.setObjectName("pushButton_schedule")
        self.Table_hdr_label = QtWidgets.QLabel(self.groupBox_2)
        self.Table_hdr_label.setGeometry(QtCore.QRect(480, 20, 341, 16))
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.Table_hdr_label.setFont(font)
        self.Table_hdr_label.setObjectName("Table_hdr_label")
        self.tableWidget_Apt = QtWidgets.QTableWidget(self.groupBox_2)
        self.tableWidget_Apt.setGeometry(QtCore.QRect(475, 41, 581, 371))
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.tableWidget_Apt.setFont(font)
        self.tableWidget_Apt.setLineWidth(1)
        self.tableWidget_Apt.setObjectName("tableWidget_Apt")
        self.tableWidget_Apt.setColumnCount(6)
        
        ColumnWidth = 87
        for i in range (6):
            self.tableWidget_Apt.setColumnWidth(i,ColumnWidth)

        self.tableWidget_Apt.setRowCount(15)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(4, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(5, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(6, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(7, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(8, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(9, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(10, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(11, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(12, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(13, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setVerticalHeaderItem(14, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(0, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(1, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(2, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(3, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(4, item)
        item = QtWidgets.QTableWidgetItem()
        self.tableWidget_Apt.setHorizontalHeaderItem(5, item)
        self.tableWidget_Apt.verticalHeader().setMinimumSectionSize(23)
        self.plainTextEdit = QtWidgets.QPlainTextEdit(self.groupBox_2, lineWrapMode = QtWidgets.QTextEdit.FixedColumnWidth, 
            placeholderText = "Please fill the above form before click the schedule button!",
            readOnly = True)
        self.plainTextEdit.setGeometry(QtCore.QRect(10, 150, 441, 191))
        self.plainTextEdit.setObjectName("plainTextEdit")
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
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.comboBox_city.setFont(font)
        self.comboBox_city.setCurrentText("")
        self.comboBox_city.setObjectName("comboBox_city")
        self.comboBox_city.addItem("")
        self.comboBox_city.addItem("")
        self.comboBox_city.addItem("")
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
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.comboBox_department.setFont(font)
        self.comboBox_department.setCurrentText("")
        self.comboBox_department.setObjectName("comboBox_department")
        self.comboBox_department.addItem("")
        self.comboBox_department.addItem("")
        self.comboBox_department.addItem("")
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
        font = QtGui.QFont()
        font.setBold(False)
        font.setWeight(50)
        self.comboBox_AptType.setFont(font)
        self.comboBox_AptType.setCurrentText("")
        self.comboBox_AptType.setObjectName("comboBox_AptType")
        self.comboBox_AptType.addItem("")
        self.comboBox_AptType.addItem("")
        self.formLayout_5.setWidget(0, QtWidgets.QFormLayout.FieldRole, self.comboBox_AptType)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        
        x = self.startDay()
        y = self.startHours()
        self.week = self.createWeekCalendar(x, y)
        self.printWeekCalendar(self.week)
        self.Validate = False
        self.patients = []
        self.day = 0
        self.time = 0
        self.numberofbookings = 0

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def ispNumvalid (self, pNum):
        pattern = re.compile('(0|82|0082)?[-\s]?[1-9]\d{8}')
        return pattern.match(pNum)

    def isemailvalid (self, email):
        pattern = '^[a-z 0-9]+[\._]?[a-z 0-9]+[\._]?[a-z 0-9]+[@]\w+[.]\w{2,3}$'
        return re.search(pattern, email)

    def validate_it(self):
        self.Validate = False
        if(self.lineEdit_f_name.text() == "" or self.lineEdit_l_name.text() == "" or self.lineEdit_address_line1.text() == "" or self.lineEdit_address_line2.text() == ""):
            self.label_validate.setText("Fill all the fields to proceed!")
        elif self.ispNumvalid(self.lineEdit_pNum.text()):
            if self.isemailvalid(self.lineEdit_email.text()):
                self.label_validate.setText("Validated successfuly")
                self.Validate = True
            else:
                self.label_validate.setText("Email address not valid!")
        else:
            self.label_validate.setText("Phone number not valid!")
        return (self.Validate)

    def schedule_it(self):
        if (self.Validate):
            if(self.tableWidget_Apt.selectedItems()):
                for item in self.tableWidget_Apt.selectedItems():
                    if item.text() == "Not Available":
                        self.plainTextEdit.setPlainText("Apointment is not available for the selected time! \rPlease select another time")
                    elif item.text() == "Booked":
                        self.plainTextEdit.setPlainText("The selected time is already booked! \rPlease select another time")
                    else:
                        self.time = item.row()
                        self.day = item.column()
                        day = self.convertIndex2Day(self.day)
                        time = self.convertIndex2Time(self.time)
                        new = self.patientInfo(self.lineEdit_f_name.text(),self.lineEdit_l_name.text(), str(self.dob_Edit.text()), self.lineEdit_address_line1.text(), self.lineEdit_address_line2.text(), self.comboBox_city.currentText(), self.comboBox_department.currentText(), self.lineEdit_pNum.text(), self.lineEdit_email.text(), self.comboBox_AptType.currentText(),day,time)
                        self.patients.append(new)
                        week2 = self.newWeekCalendar(self.week, self.day, self.time)
                        self.printWeekCalendar(week2)
                        self.plainTextEdit.setPlainText(f'Hi {self.patients[self.numberofbookings][0]} ! your {self.patients[self.numberofbookings][9]} appointment is succefully scheduled at {self.patients[self.numberofbookings][6]} department {self.patients[self.numberofbookings][5]} \rDay = {day}\rTime = {time}')
                        self.numberofbookings = self.numberofbookings+1
            else:
                self.plainTextEdit.setPlainText("Please select a siutable time from the table!")
        else:
            self.plainTextEdit.setPlainText("Please validate personal infromation first to proceed with the scheduling")


            


    def patientInfo(self, fname, surname, dob, address_line1, address_line2, address_city, address_department, pNum, email, appType, time, day):
        patient = []
        patient.append(fname)
        patient.append(surname)
        patient.append(dob)
        patient.append(address_line1)
        patient.append(address_line2)
        patient.append(address_city)
        patient.append(address_department)
        patient.append(pNum)
        patient.append(email)
        patient.append(appType)
        patient.append(time)
        patient.append(day)
        return patient

    # This creates 2 lists and the index of these lists represents the day or time (day[0] = Monday )


    def startDay(self):
        day = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']
        return (day)


    def startHours(self):
        time = ['8:00', '8:30', '9:00', '9:30', '10:30', '11:00', '11:30', '13:00', '13:30', '14:00', '14:30', '15:00' '15:30', '16:00', '16:30']
        return (time)

    # This collects the patient's appointment time input and it indexes them to select a time for the appointment


    def convertIndex2Time(self,Timeindex):
        x = self.startHours()
        timeStr = ""
        timeStr = x[Timeindex]
        return (timeStr)

    # This collects the patient's appointment day input and it indexes them to select a time for the appointment


    def convertIndex2Day(self,dayindex):
        x = self.startDay()
        dayStr = ""
        dayStr = str(x[dayindex])
        return (dayStr)

    # This allows me to format it as a table


    def createWeekCalendar(self, day, hours):
        r = 15
        c = 6
        a = [0] * r
        for i in range(r):
            a[i] = ["Available"] * c

        count = 1
        while (count < r):
            if (count > 8):
                a[count][5] = "Not Available"
            count = count + 1
        return (a)

    # This prints the table


    def printWeekCalendar(self, week):  # Imprime la tabla
        l = len(week)
        row = 0
        for i in range(l):
            self.tableWidget_Apt.setItem(row, 0 , QtWidgets.QTableWidgetItem(week[row][0]))
            self.tableWidget_Apt.setItem(row, 1 , QtWidgets.QTableWidgetItem(week[row][1]))
            self.tableWidget_Apt.setItem(row, 2 , QtWidgets.QTableWidgetItem(week[row][2]))
            self.tableWidget_Apt.setItem(row, 3 , QtWidgets.QTableWidgetItem(week[row][3]))
            self.tableWidget_Apt.setItem(row, 4 , QtWidgets.QTableWidgetItem(week[row][4]))
            self.tableWidget_Apt.setItem(row, 5 , QtWidgets.QTableWidgetItem(week[row][5]))
            row = row + 1
            


    def newWeekCalendar(self, week, day, hour):
        week[hour][day] = 'Booked'
        return (week)


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
        self.pushButton_validate.setText(_translate("MainWindow", "Validate"))
        self.label_validate.setText(_translate("MainWindow", "Click Validate Button!"))
        self.groupBox_2.setTitle(_translate("MainWindow", "Appointment details"))
        self.pushButton_schedule.setText(_translate("MainWindow", "Schedule Appointment"))
        self.Table_hdr_label.setText(_translate("MainWindow", "Please choose among the available dates and timings:"))
        item = self.tableWidget_Apt.verticalHeaderItem(0)
        item.setText(_translate("MainWindow", "8:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(1)
        item.setText(_translate("MainWindow", "8:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(2)
        item.setText(_translate("MainWindow", "9:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(3)
        item.setText(_translate("MainWindow", "9:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(4)
        item.setText(_translate("MainWindow", "10:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(5)
        item.setText(_translate("MainWindow", "10:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(6)
        item.setText(_translate("MainWindow", "11:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(7)
        item.setText(_translate("MainWindow", "11:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(8)
        item.setText(_translate("MainWindow", "13:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(9)
        item.setText(_translate("MainWindow", "13:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(10)
        item.setText(_translate("MainWindow", "14:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(11)
        item.setText(_translate("MainWindow", "14:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(12)
        item.setText(_translate("MainWindow", "15:00"))
        item = self.tableWidget_Apt.verticalHeaderItem(13)
        item.setText(_translate("MainWindow", "15:30"))
        item = self.tableWidget_Apt.verticalHeaderItem(14)
        item.setText(_translate("MainWindow", "16:00"))
        item = self.tableWidget_Apt.horizontalHeaderItem(0)
        item.setText(_translate("MainWindow", "Monday"))
        item = self.tableWidget_Apt.horizontalHeaderItem(1)
        item.setText(_translate("MainWindow", "Tuesday"))
        item = self.tableWidget_Apt.horizontalHeaderItem(2)
        item.setText(_translate("MainWindow", "Wednesday"))
        item = self.tableWidget_Apt.horizontalHeaderItem(3)
        item.setText(_translate("MainWindow", "Thursday"))
        item = self.tableWidget_Apt.horizontalHeaderItem(4)
        item.setText(_translate("MainWindow", "Friday"))
        item = self.tableWidget_Apt.horizontalHeaderItem(5)
        item.setText(_translate("MainWindow", "Saturday"))
        self.city_label.setText(_translate("MainWindow", "Pick city from the list:"))
        self.comboBox_city.setPlaceholderText(_translate("MainWindow", "Please select:"))
        self.comboBox_city.setItemText(0, _translate("MainWindow", "Daejeon"))
        self.comboBox_city.setItemText(1, _translate("MainWindow", "Seoul"))
        self.comboBox_city.setItemText(2, _translate("MainWindow", "Daegu"))
        self.department_label.setText(_translate("MainWindow", "Choose the department you want to visit:"))
        self.comboBox_department.setPlaceholderText(_translate("MainWindow", "Please select:"))
        self.comboBox_department.setItemText(0, _translate("MainWindow", "Cardiology"))
        self.comboBox_department.setItemText(1, _translate("MainWindow", "Breast Screening"))
        self.comboBox_department.setItemText(2, _translate("MainWindow", "Anesthetics"))
        self.appointment_label.setText(_translate("MainWindow", "Appointment type:"))
        self.comboBox_AptType.setPlaceholderText(_translate("MainWindow", "Please select:"))
        self.comboBox_AptType.setItemText(0, _translate("MainWindow", "In-person"))
        self.comboBox_AptType.setItemText(1, _translate("MainWindow", "Virtual"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
