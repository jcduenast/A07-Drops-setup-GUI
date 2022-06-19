<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class MainWindow
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.cmbBox_Ports = New System.Windows.Forms.ComboBox()
        Me.lblCOMPort = New System.Windows.Forms.Label()
        Me.lblBaudRate = New System.Windows.Forms.Label()
        Me.cmbBox_Baudrate = New System.Windows.Forms.ComboBox()
        Me.btnConnectPort = New System.Windows.Forms.Button()
        Me.txtReceived = New System.Windows.Forms.TextBox()
        Me.lblDataReceived = New System.Windows.Forms.Label()
        Me.txtToSend = New System.Windows.Forms.TextBox()
        Me.lblDataToSend = New System.Windows.Forms.Label()
        Me.btnSendData = New System.Windows.Forms.Button()
        Me.SerialPort1 = New System.IO.Ports.SerialPort(Me.components)
        Me.btnDisconnect = New System.Windows.Forms.Button()
        Me.SuspendLayout()
        '
        'cmbBox_Ports
        '
        Me.cmbBox_Ports.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBox_Ports.FormattingEnabled = True
        Me.cmbBox_Ports.Location = New System.Drawing.Point(667, 24)
        Me.cmbBox_Ports.Name = "cmbBox_Ports"
        Me.cmbBox_Ports.Size = New System.Drawing.Size(121, 21)
        Me.cmbBox_Ports.TabIndex = 0
        '
        'lblCOMPort
        '
        Me.lblCOMPort.AutoSize = True
        Me.lblCOMPort.Location = New System.Drawing.Point(667, 8)
        Me.lblCOMPort.Name = "lblCOMPort"
        Me.lblCOMPort.Size = New System.Drawing.Size(56, 13)
        Me.lblCOMPort.TabIndex = 1
        Me.lblCOMPort.Text = "COM Port:"
        '
        'lblBaudRate
        '
        Me.lblBaudRate.AutoSize = True
        Me.lblBaudRate.Location = New System.Drawing.Point(667, 52)
        Me.lblBaudRate.Name = "lblBaudRate"
        Me.lblBaudRate.Size = New System.Drawing.Size(53, 13)
        Me.lblBaudRate.TabIndex = 3
        Me.lblBaudRate.Text = "Baudrate:"
        '
        'cmbBox_Baudrate
        '
        Me.cmbBox_Baudrate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBox_Baudrate.FormattingEnabled = True
        Me.cmbBox_Baudrate.Items.AddRange(New Object() {"9600", "115200"})
        Me.cmbBox_Baudrate.Location = New System.Drawing.Point(667, 68)
        Me.cmbBox_Baudrate.Name = "cmbBox_Baudrate"
        Me.cmbBox_Baudrate.Size = New System.Drawing.Size(121, 21)
        Me.cmbBox_Baudrate.TabIndex = 2
        '
        'btnConnectPort
        '
        Me.btnConnectPort.Location = New System.Drawing.Point(667, 95)
        Me.btnConnectPort.Name = "btnConnectPort"
        Me.btnConnectPort.Size = New System.Drawing.Size(121, 30)
        Me.btnConnectPort.TabIndex = 4
        Me.btnConnectPort.Text = "Connect"
        Me.btnConnectPort.UseVisualStyleBackColor = True
        '
        'txtReceived
        '
        Me.txtReceived.Location = New System.Drawing.Point(664, 266)
        Me.txtReceived.Name = "txtReceived"
        Me.txtReceived.Size = New System.Drawing.Size(121, 20)
        Me.txtReceived.TabIndex = 5
        '
        'lblDataReceived
        '
        Me.lblDataReceived.AutoSize = True
        Me.lblDataReceived.Location = New System.Drawing.Point(667, 250)
        Me.lblDataReceived.Name = "lblDataReceived"
        Me.lblDataReceived.Size = New System.Drawing.Size(77, 13)
        Me.lblDataReceived.TabIndex = 6
        Me.lblDataReceived.Text = "Data received:"
        '
        'txtToSend
        '
        Me.txtToSend.Location = New System.Drawing.Point(664, 194)
        Me.txtToSend.Name = "txtToSend"
        Me.txtToSend.Size = New System.Drawing.Size(121, 20)
        Me.txtToSend.TabIndex = 7
        '
        'lblDataToSend
        '
        Me.lblDataToSend.AutoSize = True
        Me.lblDataToSend.Location = New System.Drawing.Point(667, 178)
        Me.lblDataToSend.Name = "lblDataToSend"
        Me.lblDataToSend.Size = New System.Drawing.Size(71, 13)
        Me.lblDataToSend.TabIndex = 8
        Me.lblDataToSend.Text = "Data to send:"
        '
        'btnSendData
        '
        Me.btnSendData.Location = New System.Drawing.Point(664, 217)
        Me.btnSendData.Name = "btnSendData"
        Me.btnSendData.Size = New System.Drawing.Size(121, 20)
        Me.btnSendData.TabIndex = 9
        Me.btnSendData.Text = "Send"
        Me.btnSendData.UseVisualStyleBackColor = True
        '
        'SerialPort1
        '
        '
        'btnDisconnect
        '
        Me.btnDisconnect.Location = New System.Drawing.Point(667, 131)
        Me.btnDisconnect.Name = "btnDisconnect"
        Me.btnDisconnect.Size = New System.Drawing.Size(121, 30)
        Me.btnDisconnect.TabIndex = 10
        Me.btnDisconnect.Text = "Disconnect"
        Me.btnDisconnect.UseVisualStyleBackColor = True
        '
        'MainWindow
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(800, 450)
        Me.Controls.Add(Me.btnDisconnect)
        Me.Controls.Add(Me.btnSendData)
        Me.Controls.Add(Me.lblDataToSend)
        Me.Controls.Add(Me.txtToSend)
        Me.Controls.Add(Me.lblDataReceived)
        Me.Controls.Add(Me.txtReceived)
        Me.Controls.Add(Me.btnConnectPort)
        Me.Controls.Add(Me.lblBaudRate)
        Me.Controls.Add(Me.cmbBox_Baudrate)
        Me.Controls.Add(Me.lblCOMPort)
        Me.Controls.Add(Me.cmbBox_Ports)
        Me.Name = "MainWindow"
        Me.Text = "Drops setup GUI"
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents cmbBox_Ports As ComboBox
    Friend WithEvents lblCOMPort As Label
    Friend WithEvents lblBaudRate As Label
    Friend WithEvents cmbBox_Baudrate As ComboBox
    Friend WithEvents btnConnectPort As Button
    Friend WithEvents txtReceived As TextBox
    Friend WithEvents lblDataReceived As Label
    Friend WithEvents txtToSend As TextBox
    Friend WithEvents lblDataToSend As Label
    Friend WithEvents btnSendData As Button
    Friend WithEvents SerialPort1 As IO.Ports.SerialPort
    Friend WithEvents btnDisconnect As Button
End Class
