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
        Me.txtSYMove = New System.Windows.Forms.TextBox()
        Me.btnSXHome = New System.Windows.Forms.Button()
        Me.txtSXMove = New System.Windows.Forms.TextBox()
        Me.btnSXLeft = New System.Windows.Forms.Button()
        Me.btnSXRight = New System.Windows.Forms.Button()
        Me.btnSYHome = New System.Windows.Forms.Button()
        Me.btnSZHome = New System.Windows.Forms.Button()
        Me.btnSYBackward = New System.Windows.Forms.Button()
        Me.btnSYForward = New System.Windows.Forms.Button()
        Me.txtSZMove = New System.Windows.Forms.TextBox()
        Me.btnSZDown = New System.Windows.Forms.Button()
        Me.btnSZUp = New System.Windows.Forms.Button()
        Me.btnSXYZHome = New System.Windows.Forms.Button()
        Me.lblSX = New System.Windows.Forms.Label()
        Me.lblSY = New System.Windows.Forms.Label()
        Me.lblSZ = New System.Windows.Forms.Label()
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
        'txtSYMove
        '
        Me.txtSYMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSYMove.Location = New System.Drawing.Point(15, 155)
        Me.txtSYMove.Name = "txtSYMove"
        Me.txtSYMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSYMove.TabIndex = 80
        '
        'btnSXHome
        '
        Me.btnSXHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXHome.Location = New System.Drawing.Point(100, 320)
        Me.btnSXHome.Name = "btnSXHome"
        Me.btnSXHome.Size = New System.Drawing.Size(250, 50)
        Me.btnSXHome.TabIndex = 79
        Me.btnSXHome.Text = "X: Home"
        Me.btnSXHome.UseVisualStyleBackColor = True
        '
        'txtSXMove
        '
        Me.txtSXMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSXMove.Location = New System.Drawing.Point(185, 287)
        Me.txtSXMove.Name = "txtSXMove"
        Me.txtSXMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSXMove.TabIndex = 78
        '
        'btnSXLeft
        '
        Me.btnSXLeft.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXLeft.Location = New System.Drawing.Point(100, 285)
        Me.btnSXLeft.Name = "btnSXLeft"
        Me.btnSXLeft.Size = New System.Drawing.Size(80, 30)
        Me.btnSXLeft.TabIndex = 77
        Me.btnSXLeft.Text = "X: ←"
        Me.btnSXLeft.UseVisualStyleBackColor = True
        '
        'btnSXRight
        '
        Me.btnSXRight.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXRight.Location = New System.Drawing.Point(270, 285)
        Me.btnSXRight.Name = "btnSXRight"
        Me.btnSXRight.Size = New System.Drawing.Size(80, 30)
        Me.btnSXRight.TabIndex = 76
        Me.btnSXRight.Text = "X: →"
        Me.btnSXRight.UseVisualStyleBackColor = True
        '
        'btnSYHome
        '
        Me.btnSYHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYHome.Location = New System.Drawing.Point(15, 220)
        Me.btnSYHome.Name = "btnSYHome"
        Me.btnSYHome.Size = New System.Drawing.Size(80, 60)
        Me.btnSYHome.TabIndex = 75
        Me.btnSYHome.Text = "Y: Home"
        Me.btnSYHome.UseVisualStyleBackColor = True
        '
        'btnSZHome
        '
        Me.btnSZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZHome.Location = New System.Drawing.Point(355, 220)
        Me.btnSZHome.Name = "btnSZHome"
        Me.btnSZHome.Size = New System.Drawing.Size(80, 60)
        Me.btnSZHome.TabIndex = 74
        Me.btnSZHome.Text = "Z: Home"
        Me.btnSZHome.UseVisualStyleBackColor = True
        '
        'btnSYBackward
        '
        Me.btnSYBackward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYBackward.Location = New System.Drawing.Point(15, 185)
        Me.btnSYBackward.Name = "btnSYBackward"
        Me.btnSYBackward.Size = New System.Drawing.Size(80, 30)
        Me.btnSYBackward.TabIndex = 73
        Me.btnSYBackward.Text = "Y:  ↓↓↓"
        Me.btnSYBackward.UseVisualStyleBackColor = True
        '
        'btnSYForward
        '
        Me.btnSYForward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYForward.Location = New System.Drawing.Point(15, 120)
        Me.btnSYForward.Name = "btnSYForward"
        Me.btnSYForward.Size = New System.Drawing.Size(80, 30)
        Me.btnSYForward.TabIndex = 72
        Me.btnSYForward.Text = "Y:  ↑↑↑"
        Me.btnSYForward.UseVisualStyleBackColor = True
        '
        'txtSZMove
        '
        Me.txtSZMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSZMove.Location = New System.Drawing.Point(355, 155)
        Me.txtSZMove.Name = "txtSZMove"
        Me.txtSZMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSZMove.TabIndex = 71
        '
        'btnSZDown
        '
        Me.btnSZDown.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZDown.Location = New System.Drawing.Point(355, 185)
        Me.btnSZDown.Name = "btnSZDown"
        Me.btnSZDown.Size = New System.Drawing.Size(80, 30)
        Me.btnSZDown.TabIndex = 70
        Me.btnSZDown.Text = "Z:   ↓↓↓"
        Me.btnSZDown.UseVisualStyleBackColor = True
        '
        'btnSZUp
        '
        Me.btnSZUp.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZUp.Location = New System.Drawing.Point(355, 120)
        Me.btnSZUp.Name = "btnSZUp"
        Me.btnSZUp.Size = New System.Drawing.Size(80, 30)
        Me.btnSZUp.TabIndex = 69
        Me.btnSZUp.Text = "Z:  ↑↑↑"
        Me.btnSZUp.UseVisualStyleBackColor = True
        '
        'btnSXYZHome
        '
        Me.btnSXYZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXYZHome.Location = New System.Drawing.Point(15, 285)
        Me.btnSXYZHome.Name = "btnSXYZHome"
        Me.btnSXYZHome.Size = New System.Drawing.Size(80, 85)
        Me.btnSXYZHome.TabIndex = 82
        Me.btnSXYZHome.Text = "XYZ: Home"
        Me.btnSXYZHome.UseVisualStyleBackColor = True
        '
        'lblSX
        '
        Me.lblSX.AutoSize = True
        Me.lblSX.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.lblSX.Location = New System.Drawing.Point(356, 304)
        Me.lblSX.Name = "lblSX"
        Me.lblSX.Size = New System.Drawing.Size(75, 18)
        Me.lblSX.TabIndex = 83
        Me.lblSX.Text = "X: +35000"
        '
        'lblSY
        '
        Me.lblSY.AutoSize = True
        Me.lblSY.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.lblSY.Location = New System.Drawing.Point(356, 325)
        Me.lblSY.Name = "lblSY"
        Me.lblSY.Size = New System.Drawing.Size(74, 18)
        Me.lblSY.TabIndex = 84
        Me.lblSY.Text = "Y: +35000"
        '
        'lblSZ
        '
        Me.lblSZ.AutoSize = True
        Me.lblSZ.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.lblSZ.Location = New System.Drawing.Point(356, 346)
        Me.lblSZ.Name = "lblSZ"
        Me.lblSZ.Size = New System.Drawing.Size(74, 18)
        Me.lblSZ.TabIndex = 84
        Me.lblSZ.Text = "Z: +35000"
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
        Me.Controls.Add(Me.lblSZ)
        Me.Controls.Add(Me.lblSY)
        Me.Controls.Add(Me.lblSX)
        Me.Controls.Add(Me.btnSXYZHome)
        Me.Controls.Add(Me.PictureBox5)
        Me.Controls.Add(Me.txtSYMove)
        Me.Controls.Add(Me.btnSXHome)
        Me.Controls.Add(Me.txtSXMove)
        Me.Controls.Add(Me.btnSXLeft)
        Me.Controls.Add(Me.btnSXRight)
        Me.Controls.Add(Me.btnSYHome)
        Me.Controls.Add(Me.btnSZHome)
        Me.Controls.Add(Me.btnSYBackward)
        Me.Controls.Add(Me.btnSYForward)
        Me.Controls.Add(Me.txtSZMove)
        Me.Controls.Add(Me.btnSZDown)
        Me.Controls.Add(Me.btnSZUp)
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
    Friend WithEvents txtSYMove As TextBox
    Friend WithEvents btnSXHome As Button
    Friend WithEvents txtSXMove As TextBox
    Friend WithEvents btnSXLeft As Button
    Friend WithEvents btnSXRight As Button
    Friend WithEvents btnSYHome As Button
    Friend WithEvents btnSZHome As Button
    Friend WithEvents btnSYBackward As Button
    Friend WithEvents btnSYForward As Button
    Friend WithEvents txtSZMove As TextBox
    Friend WithEvents btnSZDown As Button
    Friend WithEvents btnSZUp As Button
    Friend WithEvents btnSXYZHome As Button
    Friend WithEvents lblSX As Label
    Friend WithEvents lblSY As Label
    Friend WithEvents lblSZ As Label
    Friend WithEvents Label4 As Label
End Class
