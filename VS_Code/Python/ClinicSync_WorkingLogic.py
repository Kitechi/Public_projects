# Camila Cruz
# TEC-322 Working Logic
# ClinicSync

# This enables the code to record patient info
from datetime import datetime
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
        self.setLayout(qtw.QVBoxLayout())

        # Creat A Label
        hdr_label = qtw.QLabel(
            "Welcome to the appointment scheduler for the clinic, please enter the following information", self)
        # Change font size of label
        hdr_label.setFont(qtg.QFont('Helvetica', 18))
        self.layout().addWidget(hdr_label)

        # Creat A Name Label
        fname_label = qtw.QLabel("Enter your firstname:")
        self.layout().addWidget(fname_label)

        # Create an entry box
        fname_entry = qtw.QLineEdit(self)
        fname_entry.setObjectName("firstname")
        fname_entry.setText(" ")
        self.layout().addWidget(fname_entry)

        lname_label = qtw.QLabel("Enter your surname:")
        self.layout().addWidget(lname_label)

        # Create an entry box
        lname_entry = qtw.QLineEdit(self)
        lname_entry.setObjectName("surname")
        lname_entry.setText(" ")
        self.layout().addWidget(lname_entry)

        # Creat A Date of Birth Label
        DOB_label = qtw.QLabel("Enter date of birth (DD/MM/YYYY):")
        self.layout().addWidget(DOB_label)

        # Create an entry box
        DOB_entry = qtw.QLineEdit()
        DOB_entry.setObjectName("DOB")
        DOB_entry.setText(" ")
        self.layout().addWidget(DOB_entry)

        # Creat An Address Label
        addressline1_label = qtw.QLabel("Enter your address line 1:")
        self.layout().addWidget(addressline1_label)

        # Create an entry box
        address_line1_entry = qtw.QLineEdit()
        address_line1_entry.setObjectName("address_line1")
        address_line1_entry.setText(" ")
        self.layout().addWidget(address_line1_entry)

        addressline2_label = qtw.QLabel("Enter your address line 2:")
        self.layout().addWidget(addressline2_label)

        # Create an entry box
        address_line2_entry = qtw.QLineEdit()
        address_line2_entry.setObjectName("address_line2")
        address_line2_entry.setText(" ")
        self.layout().addWidget(address_line2_entry)

        # Creat A City Label
        city_label = qtw.QLabel("Pick city from the list:")
        self.layout().addWidget(city_label)

        # create a combo box
        city_comboBox = qtw.QComboBox(self, editable = True, insertPolicy = qtw.QComboBox.InsertAtTop)
        # Add items to the combo box
        city_comboBox.addItems(["Daejeon", "Seoul", "Daegu"])
        self.layout().addWidget(city_comboBox)


        # Creat A Department Label
        department_label = qtw.QLabel("Choose the department you want to visit:")
        self.layout().addWidget(department_label)

        # create a combo box
        department_comboBox = qtw.QComboBox(self, editable = True, insertPolicy = qtw.QComboBox.InsertAtTop)
        # Add items to the combo box
        department_comboBox.addItems(["Anesthetics", "Breast Screening", "Cardiology"])
        self.layout().addWidget(department_comboBox)


        # Creat A Phone Number Label
        phonenumber_label = qtw.QLabel("Enter your phone number:")
        self.layout().addWidget(phonenumber_label)

        # Create an entry box
        pNum_entry = qtw.QLineEdit()
        pNum_entry.setObjectName("pNum")
        pNum_entry.setText(" ")
        self.layout().addWidget(pNum_entry)

        # Creat An Email Label
        email_label = qtw.QLabel("Enter your email:")
        self.layout().addWidget(email_label)

        # Create an entry box
        email_entry = qtw.QLineEdit()
        email_entry.setObjectName("email")
        email_entry.setText(" ")
        self.layout().addWidget(email_entry)

        # Creat An Appointment Label
        appointment_label = qtw.QLabel(
            "Enter type of appointment (In-person or Virtual)")
        self.layout().addWidget(appointment_label)

        # Create an entry box
        appType_entry = qtw.QLineEdit()
        appType_entry.setObjectName("appType")
        appType_entry.setText(" ")
        self.layout().addWidget(appType_entry)

        # Creat a button
        enter_button = qtw.QPushButton("Enter", clicked=lambda: fill_form())
        self.layout().addWidget(enter_button)

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
            if(False):
                DOB_label.setText("Enter date of birth (DD/MM/YYYY): (Please enter the correct date format!)")
                DOB_entry.setText("")
            else:
                new = patientInfo(fname_entry.text(),lname_entry.text(), DOB_entry.text(), address_line1_entry.text(), address_line2_entry.text(), city_comboBox.currentText(), department_comboBox.currentText(), pNum_entry.text(), email_entry.text(), appType_entry.text())
                patients.append(new)
                DOB_label.setText("Enter date of birth (DD/MM/YYYY): (Successful!)")
                my_text.setPlainText("You have successfuly filled the form!")

            


app = qtw.QApplication([])
mw = MainWindow()

# Run the App
app.exec_()
