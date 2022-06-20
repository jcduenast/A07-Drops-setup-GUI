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
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(MainWindow))
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
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox()
        Me.PictureBox5 = New System.Windows.Forms.PictureBox()
        Me.TextBox13 = New System.Windows.Forms.TextBox()
        Me.Button37 = New System.Windows.Forms.Button()
        Me.TextBox14 = New System.Windows.Forms.TextBox()
        Me.Button38 = New System.Windows.Forms.Button()
        Me.Button39 = New System.Windows.Forms.Button()
        Me.Button40 = New System.Windows.Forms.Button()
        Me.Button41 = New System.Windows.Forms.Button()
        Me.Button42 = New System.Windows.Forms.Button()
        Me.Button43 = New System.Windows.Forms.Button()
        Me.TextBox15 = New System.Windows.Forms.TextBox()
        Me.Button44 = New System.Windows.Forms.Button()
        Me.Button45 = New System.Windows.Forms.Button()
        Me.Button46 = New System.Windows.Forms.Button()
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label4 = New System.Windows.Forms.Label()
        CType(Me.PictureBox5, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'cmbBox_Ports
        '
        Me.cmbBox_Ports.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBox_Ports.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.cmbBox_Ports.FormattingEnabled = True
        Me.cmbBox_Ports.Location = New System.Drawing.Point(1456, 25)
        Me.cmbBox_Ports.Name = "cmbBox_Ports"
        Me.cmbBox_Ports.Size = New System.Drawing.Size(121, 28)
        Me.cmbBox_Ports.TabIndex = 0
        '
        'lblCOMPort
        '
        Me.lblCOMPort.AutoSize = True
        Me.lblCOMPort.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.lblCOMPort.Location = New System.Drawing.Point(1456, 2)
        Me.lblCOMPort.Name = "lblCOMPort"
        Me.lblCOMPort.Size = New System.Drawing.Size(82, 20)
        Me.lblCOMPort.TabIndex = 1
        Me.lblCOMPort.Text = "COM Port:"
        '
        'lblBaudRate
        '
        Me.lblBaudRate.AutoSize = True
        Me.lblBaudRate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.lblBaudRate.Location = New System.Drawing.Point(1456, 64)
        Me.lblBaudRate.Name = "lblBaudRate"
        Me.lblBaudRate.Size = New System.Drawing.Size(79, 20)
        Me.lblBaudRate.TabIndex = 3
        Me.lblBaudRate.Text = "Baudrate:"
        '
        'cmbBox_Baudrate
        '
        Me.cmbBox_Baudrate.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cmbBox_Baudrate.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.cmbBox_Baudrate.FormattingEnabled = True
        Me.cmbBox_Baudrate.Items.AddRange(New Object() {"9600", "115200"})
        Me.cmbBox_Baudrate.Location = New System.Drawing.Point(1456, 87)
        Me.cmbBox_Baudrate.Name = "cmbBox_Baudrate"
        Me.cmbBox_Baudrate.Size = New System.Drawing.Size(121, 28)
        Me.cmbBox_Baudrate.TabIndex = 2
        '
        'btnConnectPort
        '
        Me.btnConnectPort.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnConnectPort.Location = New System.Drawing.Point(1456, 127)
        Me.btnConnectPort.Name = "btnConnectPort"
        Me.btnConnectPort.Size = New System.Drawing.Size(121, 30)
        Me.btnConnectPort.TabIndex = 4
        Me.btnConnectPort.Text = "Connect"
        Me.btnConnectPort.UseVisualStyleBackColor = True
        '
        'txtReceived
        '
        Me.txtReceived.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtReceived.Location = New System.Drawing.Point(1456, 337)
        Me.txtReceived.Name = "txtReceived"
        Me.txtReceived.Size = New System.Drawing.Size(121, 26)
        Me.txtReceived.TabIndex = 5
        '
        'lblDataReceived
        '
        Me.lblDataReceived.AutoSize = True
        Me.lblDataReceived.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.lblDataReceived.Location = New System.Drawing.Point(1459, 314)
        Me.lblDataReceived.Name = "lblDataReceived"
        Me.lblDataReceived.Size = New System.Drawing.Size(111, 20)
        Me.lblDataReceived.TabIndex = 6
        Me.lblDataReceived.Text = "Data received:"
        '
        'txtToSend
        '
        Me.txtToSend.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtToSend.Location = New System.Drawing.Point(1456, 233)
        Me.txtToSend.Name = "txtToSend"
        Me.txtToSend.Size = New System.Drawing.Size(121, 26)
        Me.txtToSend.TabIndex = 7
        '
        'lblDataToSend
        '
        Me.lblDataToSend.AutoSize = True
        Me.lblDataToSend.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.lblDataToSend.Location = New System.Drawing.Point(1456, 210)
        Me.lblDataToSend.Name = "lblDataToSend"
        Me.lblDataToSend.Size = New System.Drawing.Size(105, 20)
        Me.lblDataToSend.TabIndex = 8
        Me.lblDataToSend.Text = "Data to send:"
        '
        'btnSendData
        '
        Me.btnSendData.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSendData.Location = New System.Drawing.Point(1456, 265)
        Me.btnSendData.Name = "btnSendData"
        Me.btnSendData.Size = New System.Drawing.Size(121, 30)
        Me.btnSendData.TabIndex = 9
        Me.btnSendData.Text = "Send"
        Me.btnSendData.UseVisualStyleBackColor = True
        '
        'SerialPort1
        '
        '
        'btnDisconnect
        '
        Me.btnDisconnect.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnDisconnect.Location = New System.Drawing.Point(1456, 163)
        Me.btnDisconnect.Name = "btnDisconnect"
        Me.btnDisconnect.Size = New System.Drawing.Size(121, 30)
        Me.btnDisconnect.TabIndex = 10
        Me.btnDisconnect.Text = "Disconnect"
        Me.btnDisconnect.UseVisualStyleBackColor = True
        '
        'RichTextBox1
        '
        Me.RichTextBox1.Location = New System.Drawing.Point(1456, 382)
        Me.RichTextBox1.Name = "RichTextBox1"
        Me.RichTextBox1.Size = New System.Drawing.Size(121, 96)
        Me.RichTextBox1.TabIndex = 27
        Me.RichTextBox1.Text = ""
        '
        'PictureBox5
        '
        Me.PictureBox5.InitialImage = CType(resources.GetObject("PictureBox5.InitialImage"), System.Drawing.Image)
        Me.PictureBox5.Location = New System.Drawing.Point(100, 120)
        Me.PictureBox5.Name = "PictureBox5"
        Me.PictureBox5.Size = New System.Drawing.Size(250, 160)
        Me.PictureBox5.TabIndex = 81
        Me.PictureBox5.TabStop = False
        '
        'TextBox13
        '
        Me.TextBox13.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.TextBox13.Location = New System.Drawing.Point(15, 155)
        Me.TextBox13.Name = "TextBox13"
        Me.TextBox13.Size = New System.Drawing.Size(80, 26)
        Me.TextBox13.TabIndex = 80
        '
        'Button37
        '
        Me.Button37.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button37.Location = New System.Drawing.Point(100, 320)
        Me.Button37.Name = "Button37"
        Me.Button37.Size = New System.Drawing.Size(250, 50)
        Me.Button37.TabIndex = 79
        Me.Button37.Text = "X: Home"
        Me.Button37.UseVisualStyleBackColor = True
        '
        'TextBox14
        '
        Me.TextBox14.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.TextBox14.Location = New System.Drawing.Point(185, 287)
        Me.TextBox14.Name = "TextBox14"
        Me.TextBox14.Size = New System.Drawing.Size(80, 26)
        Me.TextBox14.TabIndex = 78
        '
        'Button38
        '
        Me.Button38.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button38.Location = New System.Drawing.Point(100, 285)
        Me.Button38.Name = "Button38"
        Me.Button38.Size = New System.Drawing.Size(80, 30)
        Me.Button38.TabIndex = 77
        Me.Button38.Text = "X: ←"
        Me.Button38.UseVisualStyleBackColor = True
        '
        'Button39
        '
        Me.Button39.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button39.Location = New System.Drawing.Point(270, 285)
        Me.Button39.Name = "Button39"
        Me.Button39.Size = New System.Drawing.Size(80, 30)
        Me.Button39.TabIndex = 76
        Me.Button39.Text = "X: →"
        Me.Button39.UseVisualStyleBackColor = True
        '
        'Button40
        '
        Me.Button40.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button40.Location = New System.Drawing.Point(15, 220)
        Me.Button40.Name = "Button40"
        Me.Button40.Size = New System.Drawing.Size(80, 60)
        Me.Button40.TabIndex = 75
        Me.Button40.Text = "Y: Home"
        Me.Button40.UseVisualStyleBackColor = True
        '
        'Button41
        '
        Me.Button41.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button41.Location = New System.Drawing.Point(355, 220)
        Me.Button41.Name = "Button41"
        Me.Button41.Size = New System.Drawing.Size(80, 60)
        Me.Button41.TabIndex = 74
        Me.Button41.Text = "Z: Home"
        Me.Button41.UseVisualStyleBackColor = True
        '
        'Button42
        '
        Me.Button42.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button42.Location = New System.Drawing.Point(15, 185)
        Me.Button42.Name = "Button42"
        Me.Button42.Size = New System.Drawing.Size(80, 30)
        Me.Button42.TabIndex = 73
        Me.Button42.Text = "Y:  ↓↓↓"
        Me.Button42.UseVisualStyleBackColor = True
        '
        'Button43
        '
        Me.Button43.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button43.Location = New System.Drawing.Point(15, 120)
        Me.Button43.Name = "Button43"
        Me.Button43.Size = New System.Drawing.Size(80, 30)
        Me.Button43.TabIndex = 72
        Me.Button43.Text = "Y:  ↑↑↑"
        Me.Button43.UseVisualStyleBackColor = True
        '
        'TextBox15
        '
        Me.TextBox15.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.TextBox15.Location = New System.Drawing.Point(355, 155)
        Me.TextBox15.Name = "TextBox15"
        Me.TextBox15.Size = New System.Drawing.Size(80, 26)
        Me.TextBox15.TabIndex = 71
        '
        'Button44
        '
        Me.Button44.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button44.Location = New System.Drawing.Point(355, 185)
        Me.Button44.Name = "Button44"
        Me.Button44.Size = New System.Drawing.Size(80, 30)
        Me.Button44.TabIndex = 70
        Me.Button44.Text = "Z:   ↓↓↓"
        Me.Button44.UseVisualStyleBackColor = True
        '
        'Button45
        '
        Me.Button45.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button45.Location = New System.Drawing.Point(355, 120)
        Me.Button45.Name = "Button45"
        Me.Button45.Size = New System.Drawing.Size(80, 30)
        Me.Button45.TabIndex = 69
        Me.Button45.Text = "Z:  ↑↑↑"
        Me.Button45.UseVisualStyleBackColor = True
        '
        'Button46
        '
        Me.Button46.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.Button46.Location = New System.Drawing.Point(15, 285)
        Me.Button46.Name = "Button46"
        Me.Button46.Size = New System.Drawing.Size(80, 85)
        Me.Button46.TabIndex = 82
        Me.Button46.Text = "XYZ: Home"
        Me.Button46.UseVisualStyleBackColor = True
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label1.Location = New System.Drawing.Point(356, 304)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(75, 18)
        Me.Label1.TabIndex = 83
        Me.Label1.Text = "X: +35000"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label2.Location = New System.Drawing.Point(356, 325)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(74, 18)
        Me.Label2.TabIndex = 84
        Me.Label2.Text = "Y: +35000"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label3.Location = New System.Drawing.Point(356, 346)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(74, 18)
        Me.Label3.TabIndex = 84
        Me.Label3.Text = "Z: +35000"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label4.Location = New System.Drawing.Point(356, 285)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(74, 18)
        Me.Label4.TabIndex = 85
        Me.Label4.Text = "Positions:"
        '
        'MainWindow
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1589, 629)
        Me.Controls.Add(Me.Label4)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Button46)
        Me.Controls.Add(Me.PictureBox5)
        Me.Controls.Add(Me.TextBox13)
        Me.Controls.Add(Me.Button37)
        Me.Controls.Add(Me.TextBox14)
        Me.Controls.Add(Me.Button38)
        Me.Controls.Add(Me.Button39)
        Me.Controls.Add(Me.Button40)
        Me.Controls.Add(Me.Button41)
        Me.Controls.Add(Me.Button42)
        Me.Controls.Add(Me.Button43)
        Me.Controls.Add(Me.TextBox15)
        Me.Controls.Add(Me.Button44)
        Me.Controls.Add(Me.Button45)
        Me.Controls.Add(Me.RichTextBox1)
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
        CType(Me.PictureBox5, System.ComponentModel.ISupportInitialize).EndInit()
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
    Friend WithEvents RichTextBox1 As RichTextBox
    Friend WithEvents PictureBox5 As PictureBox
    Friend WithEvents TextBox13 As TextBox
    Friend WithEvents Button37 As Button
    Friend WithEvents TextBox14 As TextBox
    Friend WithEvents Button38 As Button
    Friend WithEvents Button39 As Button
    Friend WithEvents Button40 As Button
    Friend WithEvents Button41 As Button
    Friend WithEvents Button42 As Button
    Friend WithEvents Button43 As Button
    Friend WithEvents TextBox15 As TextBox
    Friend WithEvents Button44 As Button
    Friend WithEvents Button45 As Button
    Friend WithEvents Button46 As Button
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label4 As Label
End Class
