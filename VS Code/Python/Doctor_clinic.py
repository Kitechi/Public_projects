# Camila Cruz
# TEC-322 Working Logic
# ClinicSync

# This enables the code to record patient info
import datetime as dt
from logging import PlaceHolder

import PyQt5.QtWidgets as qtw
import PyQt5.QtGui as qtg


def patientInfo(names, surnames, dob, address_line1, address_line2, address_city, address_department, pNum, email,
                appType):
    patient = []
    patient.append(names)
    patient.append(surnames)
    patient.append(dob)
    patient.append(address_line1)
    patient.append(address_line2)
    patient.append(address_city)
    patient.append(address_department)
    patient.append(pNum)
    patient.append(email)
    patient.append(appType)
    return patient

# This creates 2 lists and the index of these lists represents the day or time (day[0] = Monday )


def startDay():
    day = ['Day/Time', 'Monday', 'Tuesday',
           'Wednesday', 'Thursday', 'Friday', 'Saturday']
    return (day)


def startHours():
    time = ['8:00', '8:30', '9:00', '9:30', '10:30', '11:00', '11:30', '13:00', '13:30', '14:00', '14:30', '15:30',
            '16:00', '16:30']
    return (time)

# This collects the patient's appointment time input and it indexes them to select a time for the appointment


def convertTime2Index(
        timeStr):
    x = startHours()
    l = len(x)
    value = -1
    for i in range(l):
        if (timeStr == x[i]):
            value = i
    if (value == -1):
        print("Please type a valid time")
        print('--------------------------')
    return (value)

# This collects the patient's appointment day input and it indexes them to select a time for the appointment


def convertDay2Index(
        dayStr):
    x = startDay()
    l = len(x)

    value = -1

    for i in range(l):
        if (dayStr == str(x[i])):
            value = i
    if (value == -1):
        print("Error please type a valid day")
        print('--------------------------')
    return (value)

# This allows me to format it as a table


def createWeekCalendar(day, hours):
    r = 14
    c = 7
    a = [0] * r
    for i in range(r):
        a[i] = ["Available"] * c

    a[0] = day
    count = 1
    x = 0
    while (count < 14):
        a[count][0] = hours[x]
        if (count > 7):
            a[count][6] = "Not Available"
        x = x + 1
        count = count + 1
    return (a)

# This prints the table


def printWeekCalendar(week):  # Imprime la tabla
    l = len(week)
    for i in range(l):
        print(week[i])


def newWeekCalendar(week, dayI, hourI):
    week[hourI+1][dayI] = 'Booked'
    return (week)

def dateformat(dob):
    format = "%d/%m/%Y"
    res = False
    res = bool(datetime.strptime(dob, format))
    return (res)
        

class MainWindow(qtw.QWidget):
    def __init__(self):
        super().__init__()
        # Add a title
        self.setWindowTitle("Appointment scheduler for the clinic")

        # Set vertical layout
        # self.setLayout(qtw.QVBoxLayout())

        # Set Form layout
        form_layout = qtw.QFormLayout()
        self.setLayout(form_layout)

        # Creat A Label
        hdr_label = qtw.QLabel(
            "Welcome to the appointment scheduler for the clinic, please enter the following information", self)
        # Change font size of label
        hdr_label.setFont(qtg.QFont('Helvetica', 18))

        # Create an entry box
        f_name = qtw.QLineEdit(self)
        l_name = qtw.QLineEdit(self)
        dob = qtw.QLineEdit(self)
        address_line1 = qtw.QLineEdit(self)
        address_line2 = qtw.QLineEdit(self)
        pNum = qtw.QLineEdit(self)
        email = qtw.QLineEdit(self)
        apt_Type = qtw.QLineEdit(self)

        f_name.setObjectName("firstname")
        f_name.setText(" ")
        l_name.setObjectName("surname")
        l_name.setText(" ")
        dob.setObjectName("DOB")
        dob.setText(" ")
        address_line1.setObjectName("address_line1")
        address_line1.setText(" ")
        address_line2.setObjectName("address_line2")
        address_line2.setText(" ")
        pNum.setObjectName("pNum")
        pNum.setText(" ")
        email.setObjectName("email")
        email.setText(" ")
        apt_Type.setObjectName("apt_Type")
        apt_Type.setText(" ")

        # create a combo box
        city_comboBox = qtw.QComboBox(self, editable = True, insertPolicy = qtw.QComboBox.InsertAtTop)
        # Add items to the combo box
        city_comboBox.addItems(["Daejeon", "Seoul", "Daegu"])
        self.layout().addWidget(city_comboBox)

        # create a combo box
        department_comboBox = qtw.QComboBox(self, editable = True, insertPolicy = qtw.QComboBox.InsertAtTop)
        # Add items to the combo box
        department_comboBox.addItems(["Anesthetics", "Breast Screening", "Cardiology"])
        self.layout().addWidget(department_comboBox)

        form_layout.addRow(hdr_label)
        form_layout.addRow("Enter your firstname:", f_name)
        form_layout.addRow("Enter your surname:", l_name)
        form_layout.addRow("Enter date of birth (DD/MM/YYYY):", dob)
        form_layout.addRow("Enter your address line 1:", address_line1)
        form_layout.addRow("Enter your address line 2:",address_line2)
        form_layout.addRow("Enter your phone number:", pNum)
        form_layout.addRow("Enter your email:", email)
        form_layout.addRow("Pick city from the list:", city_comboBox)
        form_layout.addRow("Choose the department you want to visit:",department_comboBox)
        form_layout.addRow("Enter type of appointment (In-person or Virtual):", apt_Type)
        form_layout.addRow(qtw.QPushButton("Enter", clicked=lambda: fill_form()))


        # Create a text box
        my_text = qtw.QTextEdit(self, 
        lineWrapMode = qtw.QTextEdit.FixedColumnWidth, 
        lineWrapColumnOrWidth = 100,
        placeholderText = "Please fill the above form before click the enter button!",
        readOnly = True)
        self.layout().addWidget(my_text)

        # Show the app
        self.show()

        patients = []
        x = startDay()
        y = startHours()
        week = createWeekCalendar(x, y)

        def fill_form():
            format = "%d/%m/%Y"
            DOB = str(dob.text())
            try:
                dt.datetime.strptime(DOB, format)
                dob.setText("You have successfuly filled the form!")
            except ValueError:
                dob.setText(f'Please enter the correct date format! ,{DOB}')
                new = patientInfo(f_name.text(),l_name.text(), dob.text(), address_line1.text(), address_line2.text(), city_comboBox.currentText(), department_comboBox.currentText(), pNum.text(), email.text(), apt_Type.text())
                patients.append(new)
                
                # dob.setText("")

            


app = qtw.QApplication([])
mw = MainWindow()

# Run the App
app.exec_()
