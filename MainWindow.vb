Imports System.IO
Imports System.IO.Ports
Imports System.Threading
Imports System.ComponentModel

Public Class MainWindow
    'Public SerialPort1 As New SerialPort    'Set SerialPort1 as a SerialPort object
    Dim portList As Array
    Delegate Sub SetTextCallBack(ByVal [text] As String)

    Private Sub MainWindow_Load(sender As Object, e As EventArgs) Handles MyBase.Load
        portList = IO.Ports.SerialPort.GetPortNames()
        cmbBox_Ports.Items.AddRange(portList)
        btnSendData.Enabled = False
        btnDisconnect.Enabled = False
    End Sub

    Private Sub btnConnectPort_Click(sender As Object, e As EventArgs) Handles btnConnectPort.Click
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
        Catch ex As Exception
            MessageBox.Show("No COM Port or Baudrate selected", "Error")
        End Try
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
            Me.txtReceived.Text &= [text]
        End If
    End Sub

End Class
