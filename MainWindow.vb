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
    End Sub

    Sub deactivateSerialButtons()
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
        SerialPort1.Write("HSX")
    End Sub

    Private Sub btnSYHome_Click(sender As Object, e As EventArgs) Handles btnSYHome.Click
        SerialPort1.Write("HSY")
    End Sub

    Private Sub btnSZHome_Click(sender As Object, e As EventArgs) Handles btnSZHome.Click
        SerialPort1.Write("HSZ")
    End Sub

    Private Sub btnSXYZHome_Click(sender As Object, e As EventArgs) Handles btnSXYZHome.Click
        Try
            SerialPort1.Write("HSXYZ")
        Catch ex As Exception
            MessageBox.Show("No SerialPort defined", "Error")
        End Try
    End Sub
    'End of routines related to the controll of the sensor

    Private Sub MainWindow_FormClosing(sender As Object, e As FormClosingEventArgs) Handles MyBase.FormClosing
        SerialPort1.Close()
        deactivateSerialButtons()
    End Sub


End Class
