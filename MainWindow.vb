Imports System.IO
Imports System.IO.Ports
Imports System.Threading
Imports System.ComponentModel

Public Class MainWindow
    'Public SerialPort1 As New SerialPort    'Set SerialPort1 as a SerialPort object
    Dim portList As Array
    Delegate Sub SetTextCallBack(ByVal [text] As String)

    Private Sub MainWindow_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        'Excecuted at startup
        portList = IO.Ports.SerialPort.GetPortNames()
        cmbBox_Ports.Items.AddRange(portList)
        btnSendData.Enabled = False
        btnDisconnect.Enabled = False
        deactivateSerialButtons()
    End Sub

    Private Sub btnConnectPort_Click(sender As Object, e As EventArgs) Handles btnConnectPort.Click
        'Excecuted when connecting to another device
        Try
            With SerialPort1
                .Close()
                .PortName = cmbBox_Ports.Text
                .BaudRate = cmbBox_Baudrate.Text
                .DataBits = 8
                .Parity = Parity.None
                .StopBits = StopBits.One
                .Handshake = Handshake.None
                .Encoding = System.Text.Encoding.Default
                .Open()
            End With
            btnConnectPort.Enabled = False
            btnDisconnect.Enabled = True
            btnSendData.Enabled = True
            activateSerialButtons()
        Catch ex As Exception
            MessageBox.Show("No COM Port or Baudrate selected", "Error")
        End Try
    End Sub

    Sub activateSerialButtons()
        'buttons of the cofocal (S)ensor
        btnSXLeft.Enabled = True
        btnSXRight.Enabled = True
        btnSYForward.Enabled = True
        btnSYBackward.Enabled = True
        btnSZDown.Enabled = True
        btnSZUp.Enabled = True
        btnSXHome.Enabled = True
        btnSYHome.Enabled = True
        btnSZHome.Enabled = True
        btnSXYZHome.Enabled = True

        'buttons of the (D)rops generator
        btnDZUp.Enabled = True
        btnDZDown.Enabled = True
        btnDZHome.Enabled = True

        'buttons of the (C)amera/LED combo
        btnCXLeft.Enabled = True
        btnCXRight.Enabled = True
        btnCYForward.Enabled = True
        btnCYBackward.Enabled = True
        btnCZDown.Enabled = True
        btnCZUp.Enabled = True
        btnCXHome.Enabled = True
        btnCYHome.Enabled = True
        btnCZHome.Enabled = True
        btnCXYZHome.Enabled = True

        'buttons of the (W)ave generator
        btnWXLeft.Enabled = True
        btnWXRight.Enabled = True
        btnWYForward.Enabled = True
        btnWYBackward.Enabled = True
        btnWZDown.Enabled = True
        btnWZUp.Enabled = True
        btnWXHome.Enabled = True
        btnWYHome.Enabled = True
        btnWZHome.Enabled = True
        btnWXYZHome.Enabled = True
    End Sub

    Sub deactivateSerialButtons()
        'buttons of the cofocal (S)ensor
        btnSXLeft.Enabled = False
        btnSXRight.Enabled = False
        btnSYForward.Enabled = False
        btnSYBackward.Enabled = False
        btnSZDown.Enabled = False
        btnSZUp.Enabled = False
        btnSXHome.Enabled = False
        btnSYHome.Enabled = False
        btnSZHome.Enabled = False
        btnSXYZHome.Enabled = False

        'buttons of the (D)rops generator
        btnDZUp.Enabled = False
        btnDZDown.Enabled = False
        btnDZHome.Enabled = False

        'buttons of the (C)amera/LED combo
        btnCXLeft.Enabled = False
        btnCXRight.Enabled = False
        btnCYForward.Enabled = False
        btnCYBackward.Enabled = False
        btnCZDown.Enabled = False
        btnCZUp.Enabled = False
        btnCXHome.Enabled = False
        btnCYHome.Enabled = False
        btnCZHome.Enabled = False
        btnCXYZHome.Enabled = False

        'buttons of the (W)ave generator
        btnWXLeft.Enabled = False
        btnWXRight.Enabled = False
        btnWYForward.Enabled = False
        btnWYBackward.Enabled = False
        btnWZDown.Enabled = False
        btnWZUp.Enabled = False
        btnWXHome.Enabled = False
        btnWYHome.Enabled = False
        btnWZHome.Enabled = False
        btnWXYZHome.Enabled = False
    End Sub


    Private Sub btnDisconnect_Click(sender As Object, e As EventArgs) Handles btnDisconnect.Click
        SerialPort1.Close()
        btnDisconnect.Enabled = False
        btnSendData.Enabled = False
        btnConnectPort.Enabled = True
    End Sub

    Private Sub btnSendData_Click(sender As Object, e As EventArgs) Handles btnSendData.Click
        Dim rx As String
        'To read A0 port send 2 through COM port
        SerialPort1.Write(txtToSend.Text & vbCr)
    End Sub

    Private Sub SerialPort1_DataReceived(sender As Object, e As SerialDataReceivedEventArgs) Handles SerialPort1.DataReceived
        ReceiveText(SerialPort1.ReadExisting)
    End Sub

    Private Sub ReceiveText(ByVal [text] As String)
        If Me.txtReceived.InvokeRequired Then
            Dim x As New SetTextCallBack(AddressOf ReceiveText)
            Me.Invoke(x, New Object() {(text)})
        Else
            Me.txtReceived.Text = [text]
        End If
    End Sub

    'Start of routines related to the controll of the sensor
    Private Sub btnSXRight_Click(sender As Object, e As EventArgs) Handles btnSXRight.Click
        'Send the command to move to the right the amount especified in the box
        SerialPort1.Write("MXS: " + txtSXMove.Text + "\n")
    End Sub

    Private Sub btnSXLeft_Click(sender As Object, e As EventArgs) Handles btnSXLeft.Click
        SerialPort1.Write("MXS: -" + txtSXMove.Text)
    End Sub

    Private Sub btnSYForward_Click(sender As Object, e As EventArgs) Handles btnSYForward.Click
        'Send the command to move to forward the amount especified in the box
        SerialPort1.Write("MYS: " + txtSYMove.Text)
    End Sub

    Private Sub btnSYBackward_Click(sender As Object, e As EventArgs) Handles btnSYBackward.Click
        SerialPort1.Write("MYS: -" + txtSYMove.Text)
    End Sub

    Private Sub btnSZUp_Click(sender As Object, e As EventArgs) Handles btnSZUp.Click
        'Send the command to move up the amount especified in the box
        SerialPort1.Write("MZS: " + txtSZMove.Text)
    End Sub

    Private Sub btnSZDown_Click(sender As Object, e As EventArgs) Handles btnSZDown.Click
        SerialPort1.Write("MZS: -" + txtSZMove.Text)
    End Sub

    Private Sub btnSXHome_Click(sender As Object, e As EventArgs) Handles btnSXHome.Click
        SerialPort1.Write("SXH")
    End Sub

    Private Sub btnSYHome_Click(sender As Object, e As EventArgs) Handles btnSYHome.Click
        SerialPort1.Write("SYH")
    End Sub

    Private Sub btnSZHome_Click(sender As Object, e As EventArgs) Handles btnSZHome.Click
        SerialPort1.Write("SZH")
    End Sub

    Private Sub btnSXYZHome_Click(sender As Object, e As EventArgs) Handles btnSXYZHome.Click
        Try
            SerialPort1.Write("SXYZH")
        Catch ex As Exception
            MessageBox.Show("No SerialPort defined", "Error")
        End Try
    End Sub
    'End of routines related to the controll of the sensor

    Private Sub MainWindow_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        SerialPort1.Close()
        deactivateSerialButtons()
    End Sub

    Private Sub btnDZUp_Click(sender As Object, e As EventArgs) Handles btnDZUp.Click
        SerialPort1.Write("MF: " + txtDZMove.Text)
    End Sub

    Private Sub btnDZDown_Click(sender As Object, e As EventArgs) Handles btnDZDown.Click
        SerialPort1.Write("MF: -" + txtDZMove.Text)
    End Sub

    Private Sub btnDZHome_Click(sender As Object, e As EventArgs) Handles btnDZHome.Click
        SerialPort1.Write("FH")
    End Sub

    'buttons of the (C)amera/LED
    Private Sub btnCXRight_Click(sender As Object, e As EventArgs) Handles btnCXRight.Click
        SerialPort1.Write("MX: -" + txtCXMove.Text)
    End Sub

    Private Sub btnCXLeft_Click(sender As Object, e As EventArgs) Handles btnCXLeft.Click
        SerialPort1.Write("MX: -" + txtCXMove.Text)
    End Sub

    Private Sub btnCYForward_Click(sender As Object, e As EventArgs) Handles btnCYForward.Click
        SerialPort1.Write("MY: " + txtCYMove.Text)
    End Sub

    Private Sub btnCYBackward_Click(sender As Object, e As EventArgs) Handles btnCYBackward.Click
        SerialPort1.Write("MY: -" + txtCYMove.Text)
    End Sub

    Private Sub btnCZUp_Click(sender As Object, e As EventArgs) Handles btnCZUp.Click
        SerialPort1.Write("MZ: " + txtCZMove.Text)
    End Sub

    Private Sub btnCZDown_Click(sender As Object, e As EventArgs) Handles btnCZDown.Click
        SerialPort1.Write("MZ: -" + txtCZMove.Text)
    End Sub

    Private Sub btnCXHome_Click(sender As Object, e As EventArgs) Handles btnCXHome.Click
        SerialPort1.Write("CXH")
    End Sub

    Private Sub btnCYHome_Click(sender As Object, e As EventArgs) Handles btnCYHome.Click
        SerialPort1.Write("CYH")
    End Sub

    Private Sub btnCZHome_Click(sender As Object, e As EventArgs) Handles btnCZHome.Click
        SerialPort1.Write("CZH")
    End Sub

    Private Sub btnCXYZHome_Click(sender As Object, e As EventArgs) Handles btnCXYZHome.Click
        SerialPort1.Write("CXYZH")
    End Sub

    Private Sub btnWXRight_Click(sender As Object, e As EventArgs) Handles btnWXRight.Click
        SerialPort1.Write("MWX: " + txtWXMove.Text)
    End Sub

    Private Sub btnWXLeft_Click(sender As Object, e As EventArgs) Handles btnWXLeft.Click
        SerialPort1.Write("MWX: -" + txtWXMove.Text)
    End Sub

    Private Sub btnWYForward_Click(sender As Object, e As EventArgs) Handles btnWYForward.Click
        SerialPort1.Write("MWY: " + txtWYMove.Text)
    End Sub

    Private Sub btnWYBackward_Click(sender As Object, e As EventArgs) Handles btnWYBackward.Click
        SerialPort1.Write("MWY: -" + txtWYMove.Text)
    End Sub

    Private Sub btnWZUp_Click(sender As Object, e As EventArgs) Handles btnWZUp.Click
        SerialPort1.Write("MWZ: " + txtWZMove.Text)
    End Sub

    Private Sub btnWZDown_Click(sender As Object, e As EventArgs) Handles btnWZDown.Click
        SerialPort1.Write("MWZ: -" + txtWZMove.Text)
    End Sub

    Private Sub btnWXHome_Click(sender As Object, e As EventArgs) Handles btnWXHome.Click
        SerialPort1.Write("WXH")
    End Sub

    Private Sub btnWYHome_Click(sender As Object, e As EventArgs) Handles btnWYHome.Click
        SerialPort1.Write("WYH")
    End Sub

    Private Sub btnWZHome_Click(sender As Object, e As EventArgs) Handles btnWZHome.Click
        SerialPort1.Write("WZH")
    End Sub

    Private Sub btnWXYZHome_Click(sender As Object, e As EventArgs) Handles btnWXYZHome.Click
        SerialPort1.Write("WXYZH")
    End Sub
End Class
