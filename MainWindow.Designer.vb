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
        Me.RichTextBox1 = New System.Windows.Forms.RichTextBox()
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
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Label2 = New System.Windows.Forms.Label()
        Me.Label3 = New System.Windows.Forms.Label()
        Me.Label5 = New System.Windows.Forms.Label()
        Me.btnCXYZHome = New System.Windows.Forms.Button()
        Me.txtCYMove = New System.Windows.Forms.TextBox()
        Me.btnCXHome = New System.Windows.Forms.Button()
        Me.txtCXMove = New System.Windows.Forms.TextBox()
        Me.btnCXLeft = New System.Windows.Forms.Button()
        Me.btnCXRight = New System.Windows.Forms.Button()
        Me.btnCYHome = New System.Windows.Forms.Button()
        Me.btnCZHome = New System.Windows.Forms.Button()
        Me.btnCYBackward = New System.Windows.Forms.Button()
        Me.btnCYForward = New System.Windows.Forms.Button()
        Me.txtCZMove = New System.Windows.Forms.TextBox()
        Me.btnCZDown = New System.Windows.Forms.Button()
        Me.btnCZUp = New System.Windows.Forms.Button()
        Me.Label6 = New System.Windows.Forms.Label()
        Me.Label7 = New System.Windows.Forms.Label()
        Me.Label8 = New System.Windows.Forms.Label()
        Me.Label9 = New System.Windows.Forms.Label()
        Me.btnWXYZHome = New System.Windows.Forms.Button()
        Me.txtWYMove = New System.Windows.Forms.TextBox()
        Me.btnWXHome = New System.Windows.Forms.Button()
        Me.txtWXMove = New System.Windows.Forms.TextBox()
        Me.btnWXLeft = New System.Windows.Forms.Button()
        Me.btnWXRight = New System.Windows.Forms.Button()
        Me.btnWYHome = New System.Windows.Forms.Button()
        Me.btnWZHome = New System.Windows.Forms.Button()
        Me.btnWYBackward = New System.Windows.Forms.Button()
        Me.btnWYForward = New System.Windows.Forms.Button()
        Me.txtWZMove = New System.Windows.Forms.TextBox()
        Me.btnWZDown = New System.Windows.Forms.Button()
        Me.btnWZUp = New System.Windows.Forms.Button()
        Me.Label10 = New System.Windows.Forms.Label()
        Me.Label11 = New System.Windows.Forms.Label()
        Me.btnDZHome = New System.Windows.Forms.Button()
        Me.txtDZMove = New System.Windows.Forms.TextBox()
        Me.btnDZDown = New System.Windows.Forms.Button()
        Me.btnDZUp = New System.Windows.Forms.Button()
        Me.PictureBox4 = New System.Windows.Forms.PictureBox()
        Me.PictureBox3 = New System.Windows.Forms.PictureBox()
        Me.PictureBox2 = New System.Windows.Forms.PictureBox()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.PictureBox5 = New System.Windows.Forms.PictureBox()
        CType(Me.PictureBox4, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
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
        'txtSYMove
        '
        Me.txtSYMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSYMove.Location = New System.Drawing.Point(21, 238)
        Me.txtSYMove.Name = "txtSYMove"
        Me.txtSYMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSYMove.TabIndex = 80
        '
        'btnSXHome
        '
        Me.btnSXHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXHome.Location = New System.Drawing.Point(106, 403)
        Me.btnSXHome.Name = "btnSXHome"
        Me.btnSXHome.Size = New System.Drawing.Size(250, 50)
        Me.btnSXHome.TabIndex = 79
        Me.btnSXHome.Text = "X: Home"
        Me.btnSXHome.UseVisualStyleBackColor = True
        '
        'txtSXMove
        '
        Me.txtSXMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSXMove.Location = New System.Drawing.Point(191, 370)
        Me.txtSXMove.Name = "txtSXMove"
        Me.txtSXMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSXMove.TabIndex = 78
        '
        'btnSXLeft
        '
        Me.btnSXLeft.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXLeft.Location = New System.Drawing.Point(106, 368)
        Me.btnSXLeft.Name = "btnSXLeft"
        Me.btnSXLeft.Size = New System.Drawing.Size(80, 30)
        Me.btnSXLeft.TabIndex = 77
        Me.btnSXLeft.Text = "X: ←"
        Me.btnSXLeft.UseVisualStyleBackColor = True
        '
        'btnSXRight
        '
        Me.btnSXRight.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXRight.Location = New System.Drawing.Point(276, 368)
        Me.btnSXRight.Name = "btnSXRight"
        Me.btnSXRight.Size = New System.Drawing.Size(80, 30)
        Me.btnSXRight.TabIndex = 76
        Me.btnSXRight.Text = "X: →"
        Me.btnSXRight.UseVisualStyleBackColor = True
        '
        'btnSYHome
        '
        Me.btnSYHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYHome.Location = New System.Drawing.Point(21, 303)
        Me.btnSYHome.Name = "btnSYHome"
        Me.btnSYHome.Size = New System.Drawing.Size(80, 60)
        Me.btnSYHome.TabIndex = 75
        Me.btnSYHome.Text = "Y: Home"
        Me.btnSYHome.UseVisualStyleBackColor = True
        '
        'btnSZHome
        '
        Me.btnSZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZHome.Location = New System.Drawing.Point(361, 303)
        Me.btnSZHome.Name = "btnSZHome"
        Me.btnSZHome.Size = New System.Drawing.Size(80, 60)
        Me.btnSZHome.TabIndex = 74
        Me.btnSZHome.Text = "Z: Home"
        Me.btnSZHome.UseVisualStyleBackColor = True
        '
        'btnSYBackward
        '
        Me.btnSYBackward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYBackward.Location = New System.Drawing.Point(21, 268)
        Me.btnSYBackward.Name = "btnSYBackward"
        Me.btnSYBackward.Size = New System.Drawing.Size(80, 30)
        Me.btnSYBackward.TabIndex = 73
        Me.btnSYBackward.Text = "Y:  ↓↓↓"
        Me.btnSYBackward.UseVisualStyleBackColor = True
        '
        'btnSYForward
        '
        Me.btnSYForward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSYForward.Location = New System.Drawing.Point(21, 203)
        Me.btnSYForward.Name = "btnSYForward"
        Me.btnSYForward.Size = New System.Drawing.Size(80, 30)
        Me.btnSYForward.TabIndex = 72
        Me.btnSYForward.Text = "Y:  ↑↑↑"
        Me.btnSYForward.UseVisualStyleBackColor = True
        '
        'txtSZMove
        '
        Me.txtSZMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtSZMove.Location = New System.Drawing.Point(361, 238)
        Me.txtSZMove.Name = "txtSZMove"
        Me.txtSZMove.Size = New System.Drawing.Size(80, 26)
        Me.txtSZMove.TabIndex = 71
        '
        'btnSZDown
        '
        Me.btnSZDown.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZDown.Location = New System.Drawing.Point(361, 268)
        Me.btnSZDown.Name = "btnSZDown"
        Me.btnSZDown.Size = New System.Drawing.Size(80, 30)
        Me.btnSZDown.TabIndex = 70
        Me.btnSZDown.Text = "Z:   ↓↓↓"
        Me.btnSZDown.UseVisualStyleBackColor = True
        '
        'btnSZUp
        '
        Me.btnSZUp.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSZUp.Location = New System.Drawing.Point(361, 203)
        Me.btnSZUp.Name = "btnSZUp"
        Me.btnSZUp.Size = New System.Drawing.Size(80, 30)
        Me.btnSZUp.TabIndex = 69
        Me.btnSZUp.Text = "Z:  ↑↑↑"
        Me.btnSZUp.UseVisualStyleBackColor = True
        '
        'btnSXYZHome
        '
        Me.btnSXYZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnSXYZHome.Location = New System.Drawing.Point(21, 368)
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
        Me.lblSX.Location = New System.Drawing.Point(362, 387)
        Me.lblSX.Name = "lblSX"
        Me.lblSX.Size = New System.Drawing.Size(75, 18)
        Me.lblSX.TabIndex = 83
        Me.lblSX.Text = "X: +35000"
        '
        'lblSY
        '
        Me.lblSY.AutoSize = True
        Me.lblSY.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.lblSY.Location = New System.Drawing.Point(362, 408)
        Me.lblSY.Name = "lblSY"
        Me.lblSY.Size = New System.Drawing.Size(74, 18)
        Me.lblSY.TabIndex = 84
        Me.lblSY.Text = "Y: +35000"
        '
        'lblSZ
        '
        Me.lblSZ.AutoSize = True
        Me.lblSZ.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.lblSZ.Location = New System.Drawing.Point(362, 429)
        Me.lblSZ.Name = "lblSZ"
        Me.lblSZ.Size = New System.Drawing.Size(74, 18)
        Me.lblSZ.TabIndex = 84
        Me.lblSZ.Text = "Z: +35000"
        '
        'Label4
        '
        Me.Label4.AutoSize = True
        Me.Label4.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label4.Location = New System.Drawing.Point(362, 368)
        Me.Label4.Name = "Label4"
        Me.Label4.Size = New System.Drawing.Size(74, 18)
        Me.Label4.TabIndex = 85
        Me.Label4.Text = "Positions:"
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label1.Location = New System.Drawing.Point(818, 635)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(74, 18)
        Me.Label1.TabIndex = 103
        Me.Label1.Text = "Positions:"
        '
        'Label2
        '
        Me.Label2.AutoSize = True
        Me.Label2.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label2.Location = New System.Drawing.Point(818, 696)
        Me.Label2.Name = "Label2"
        Me.Label2.Size = New System.Drawing.Size(74, 18)
        Me.Label2.TabIndex = 102
        Me.Label2.Text = "Z: +35000"
        '
        'Label3
        '
        Me.Label3.AutoSize = True
        Me.Label3.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label3.Location = New System.Drawing.Point(818, 675)
        Me.Label3.Name = "Label3"
        Me.Label3.Size = New System.Drawing.Size(74, 18)
        Me.Label3.TabIndex = 101
        Me.Label3.Text = "Y: +35000"
        '
        'Label5
        '
        Me.Label5.AutoSize = True
        Me.Label5.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label5.Location = New System.Drawing.Point(818, 654)
        Me.Label5.Name = "Label5"
        Me.Label5.Size = New System.Drawing.Size(75, 18)
        Me.Label5.TabIndex = 100
        Me.Label5.Text = "X: +35000"
        '
        'btnCXYZHome
        '
        Me.btnCXYZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCXYZHome.Location = New System.Drawing.Point(477, 635)
        Me.btnCXYZHome.Name = "btnCXYZHome"
        Me.btnCXYZHome.Size = New System.Drawing.Size(80, 85)
        Me.btnCXYZHome.TabIndex = 99
        Me.btnCXYZHome.Text = "XYZ: Home"
        Me.btnCXYZHome.UseVisualStyleBackColor = True
        '
        'txtCYMove
        '
        Me.txtCYMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtCYMove.Location = New System.Drawing.Point(477, 505)
        Me.txtCYMove.Name = "txtCYMove"
        Me.txtCYMove.Size = New System.Drawing.Size(80, 26)
        Me.txtCYMove.TabIndex = 97
        '
        'btnCXHome
        '
        Me.btnCXHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCXHome.Location = New System.Drawing.Point(562, 670)
        Me.btnCXHome.Name = "btnCXHome"
        Me.btnCXHome.Size = New System.Drawing.Size(250, 50)
        Me.btnCXHome.TabIndex = 96
        Me.btnCXHome.Text = "X: Home"
        Me.btnCXHome.UseVisualStyleBackColor = True
        '
        'txtCXMove
        '
        Me.txtCXMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtCXMove.Location = New System.Drawing.Point(647, 637)
        Me.txtCXMove.Name = "txtCXMove"
        Me.txtCXMove.Size = New System.Drawing.Size(80, 26)
        Me.txtCXMove.TabIndex = 95
        '
        'btnCXLeft
        '
        Me.btnCXLeft.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCXLeft.Location = New System.Drawing.Point(562, 635)
        Me.btnCXLeft.Name = "btnCXLeft"
        Me.btnCXLeft.Size = New System.Drawing.Size(80, 30)
        Me.btnCXLeft.TabIndex = 94
        Me.btnCXLeft.Text = "X: ←"
        Me.btnCXLeft.UseVisualStyleBackColor = True
        '
        'btnCXRight
        '
        Me.btnCXRight.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCXRight.Location = New System.Drawing.Point(732, 635)
        Me.btnCXRight.Name = "btnCXRight"
        Me.btnCXRight.Size = New System.Drawing.Size(80, 30)
        Me.btnCXRight.TabIndex = 93
        Me.btnCXRight.Text = "X: →"
        Me.btnCXRight.UseVisualStyleBackColor = True
        '
        'btnCYHome
        '
        Me.btnCYHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCYHome.Location = New System.Drawing.Point(477, 570)
        Me.btnCYHome.Name = "btnCYHome"
        Me.btnCYHome.Size = New System.Drawing.Size(80, 60)
        Me.btnCYHome.TabIndex = 92
        Me.btnCYHome.Text = "Y: Home"
        Me.btnCYHome.UseVisualStyleBackColor = True
        '
        'btnCZHome
        '
        Me.btnCZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCZHome.Location = New System.Drawing.Point(817, 570)
        Me.btnCZHome.Name = "btnCZHome"
        Me.btnCZHome.Size = New System.Drawing.Size(80, 60)
        Me.btnCZHome.TabIndex = 91
        Me.btnCZHome.Text = "Z: Home"
        Me.btnCZHome.UseVisualStyleBackColor = True
        '
        'btnCYBackward
        '
        Me.btnCYBackward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCYBackward.Location = New System.Drawing.Point(477, 535)
        Me.btnCYBackward.Name = "btnCYBackward"
        Me.btnCYBackward.Size = New System.Drawing.Size(80, 30)
        Me.btnCYBackward.TabIndex = 90
        Me.btnCYBackward.Text = "Y:  ↓↓↓"
        Me.btnCYBackward.UseVisualStyleBackColor = True
        '
        'btnCYForward
        '
        Me.btnCYForward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCYForward.Location = New System.Drawing.Point(477, 470)
        Me.btnCYForward.Name = "btnCYForward"
        Me.btnCYForward.Size = New System.Drawing.Size(80, 30)
        Me.btnCYForward.TabIndex = 89
        Me.btnCYForward.Text = "Y:  ↑↑↑"
        Me.btnCYForward.UseVisualStyleBackColor = True
        '
        'txtCZMove
        '
        Me.txtCZMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtCZMove.Location = New System.Drawing.Point(817, 505)
        Me.txtCZMove.Name = "txtCZMove"
        Me.txtCZMove.Size = New System.Drawing.Size(80, 26)
        Me.txtCZMove.TabIndex = 88
        '
        'btnCZDown
        '
        Me.btnCZDown.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCZDown.Location = New System.Drawing.Point(817, 535)
        Me.btnCZDown.Name = "btnCZDown"
        Me.btnCZDown.Size = New System.Drawing.Size(80, 30)
        Me.btnCZDown.TabIndex = 87
        Me.btnCZDown.Text = "Z:   ↓↓↓"
        Me.btnCZDown.UseVisualStyleBackColor = True
        '
        'btnCZUp
        '
        Me.btnCZUp.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnCZUp.Location = New System.Drawing.Point(817, 470)
        Me.btnCZUp.Name = "btnCZUp"
        Me.btnCZUp.Size = New System.Drawing.Size(80, 30)
        Me.btnCZUp.TabIndex = 86
        Me.btnCZUp.Text = "Z:  ↑↑↑"
        Me.btnCZUp.UseVisualStyleBackColor = True
        '
        'Label6
        '
        Me.Label6.AutoSize = True
        Me.Label6.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label6.Location = New System.Drawing.Point(1276, 368)
        Me.Label6.Name = "Label6"
        Me.Label6.Size = New System.Drawing.Size(74, 18)
        Me.Label6.TabIndex = 121
        Me.Label6.Text = "Positions:"
        '
        'Label7
        '
        Me.Label7.AutoSize = True
        Me.Label7.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label7.Location = New System.Drawing.Point(1276, 429)
        Me.Label7.Name = "Label7"
        Me.Label7.Size = New System.Drawing.Size(74, 18)
        Me.Label7.TabIndex = 120
        Me.Label7.Text = "Z: +35000"
        '
        'Label8
        '
        Me.Label8.AutoSize = True
        Me.Label8.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label8.Location = New System.Drawing.Point(1276, 408)
        Me.Label8.Name = "Label8"
        Me.Label8.Size = New System.Drawing.Size(74, 18)
        Me.Label8.TabIndex = 119
        Me.Label8.Text = "Y: +35000"
        '
        'Label9
        '
        Me.Label9.AutoSize = True
        Me.Label9.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label9.Location = New System.Drawing.Point(1276, 387)
        Me.Label9.Name = "Label9"
        Me.Label9.Size = New System.Drawing.Size(75, 18)
        Me.Label9.TabIndex = 118
        Me.Label9.Text = "X: +35000"
        '
        'btnWXYZHome
        '
        Me.btnWXYZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWXYZHome.Location = New System.Drawing.Point(935, 368)
        Me.btnWXYZHome.Name = "btnWXYZHome"
        Me.btnWXYZHome.Size = New System.Drawing.Size(80, 85)
        Me.btnWXYZHome.TabIndex = 117
        Me.btnWXYZHome.Text = "XYZ: Home"
        Me.btnWXYZHome.UseVisualStyleBackColor = True
        '
        'txtWYMove
        '
        Me.txtWYMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtWYMove.Location = New System.Drawing.Point(935, 238)
        Me.txtWYMove.Name = "txtWYMove"
        Me.txtWYMove.Size = New System.Drawing.Size(80, 26)
        Me.txtWYMove.TabIndex = 115
        '
        'btnWXHome
        '
        Me.btnWXHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWXHome.Location = New System.Drawing.Point(1020, 403)
        Me.btnWXHome.Name = "btnWXHome"
        Me.btnWXHome.Size = New System.Drawing.Size(250, 50)
        Me.btnWXHome.TabIndex = 114
        Me.btnWXHome.Text = "X: Home"
        Me.btnWXHome.UseVisualStyleBackColor = True
        '
        'txtWXMove
        '
        Me.txtWXMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtWXMove.Location = New System.Drawing.Point(1105, 370)
        Me.txtWXMove.Name = "txtWXMove"
        Me.txtWXMove.Size = New System.Drawing.Size(80, 26)
        Me.txtWXMove.TabIndex = 113
        '
        'btnWXLeft
        '
        Me.btnWXLeft.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWXLeft.Location = New System.Drawing.Point(1020, 368)
        Me.btnWXLeft.Name = "btnWXLeft"
        Me.btnWXLeft.Size = New System.Drawing.Size(80, 30)
        Me.btnWXLeft.TabIndex = 112
        Me.btnWXLeft.Text = "X: ←"
        Me.btnWXLeft.UseVisualStyleBackColor = True
        '
        'btnWXRight
        '
        Me.btnWXRight.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWXRight.Location = New System.Drawing.Point(1190, 368)
        Me.btnWXRight.Name = "btnWXRight"
        Me.btnWXRight.Size = New System.Drawing.Size(80, 30)
        Me.btnWXRight.TabIndex = 111
        Me.btnWXRight.Text = "X: →"
        Me.btnWXRight.UseVisualStyleBackColor = True
        '
        'btnWYHome
        '
        Me.btnWYHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWYHome.Location = New System.Drawing.Point(935, 303)
        Me.btnWYHome.Name = "btnWYHome"
        Me.btnWYHome.Size = New System.Drawing.Size(80, 60)
        Me.btnWYHome.TabIndex = 110
        Me.btnWYHome.Text = "Y: Home"
        Me.btnWYHome.UseVisualStyleBackColor = True
        '
        'btnWZHome
        '
        Me.btnWZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWZHome.Location = New System.Drawing.Point(1275, 303)
        Me.btnWZHome.Name = "btnWZHome"
        Me.btnWZHome.Size = New System.Drawing.Size(80, 60)
        Me.btnWZHome.TabIndex = 109
        Me.btnWZHome.Text = "Z: Home"
        Me.btnWZHome.UseVisualStyleBackColor = True
        '
        'btnWYBackward
        '
        Me.btnWYBackward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWYBackward.Location = New System.Drawing.Point(935, 268)
        Me.btnWYBackward.Name = "btnWYBackward"
        Me.btnWYBackward.Size = New System.Drawing.Size(80, 30)
        Me.btnWYBackward.TabIndex = 108
        Me.btnWYBackward.Text = "Y:  ↓↓↓"
        Me.btnWYBackward.UseVisualStyleBackColor = True
        '
        'btnWYForward
        '
        Me.btnWYForward.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWYForward.Location = New System.Drawing.Point(935, 203)
        Me.btnWYForward.Name = "btnWYForward"
        Me.btnWYForward.Size = New System.Drawing.Size(80, 30)
        Me.btnWYForward.TabIndex = 107
        Me.btnWYForward.Text = "Y:  ↑↑↑"
        Me.btnWYForward.UseVisualStyleBackColor = True
        '
        'txtWZMove
        '
        Me.txtWZMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtWZMove.Location = New System.Drawing.Point(1275, 238)
        Me.txtWZMove.Name = "txtWZMove"
        Me.txtWZMove.Size = New System.Drawing.Size(80, 26)
        Me.txtWZMove.TabIndex = 106
        '
        'btnWZDown
        '
        Me.btnWZDown.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWZDown.Location = New System.Drawing.Point(1275, 268)
        Me.btnWZDown.Name = "btnWZDown"
        Me.btnWZDown.Size = New System.Drawing.Size(80, 30)
        Me.btnWZDown.TabIndex = 105
        Me.btnWZDown.Text = "Z:   ↓↓↓"
        Me.btnWZDown.UseVisualStyleBackColor = True
        '
        'btnWZUp
        '
        Me.btnWZUp.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnWZUp.Location = New System.Drawing.Point(1275, 203)
        Me.btnWZUp.Name = "btnWZUp"
        Me.btnWZUp.Size = New System.Drawing.Size(80, 30)
        Me.btnWZUp.TabIndex = 104
        Me.btnWZUp.Text = "Z:  ↑↑↑"
        Me.btnWZUp.UseVisualStyleBackColor = True
        '
        'Label10
        '
        Me.Label10.AutoSize = True
        Me.Label10.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label10.Location = New System.Drawing.Point(643, 172)
        Me.Label10.Name = "Label10"
        Me.Label10.Size = New System.Drawing.Size(74, 18)
        Me.Label10.TabIndex = 139
        Me.Label10.Text = "Positions:"
        '
        'Label11
        '
        Me.Label11.AutoSize = True
        Me.Label11.Font = New System.Drawing.Font("Microsoft Sans Serif", 11.0!)
        Me.Label11.Location = New System.Drawing.Point(729, 172)
        Me.Label11.Name = "Label11"
        Me.Label11.Size = New System.Drawing.Size(74, 18)
        Me.Label11.TabIndex = 138
        Me.Label11.Text = "Z: +35000"
        '
        'btnDZHome
        '
        Me.btnDZHome.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnDZHome.Location = New System.Drawing.Point(732, 109)
        Me.btnDZHome.Name = "btnDZHome"
        Me.btnDZHome.Size = New System.Drawing.Size(80, 60)
        Me.btnDZHome.TabIndex = 127
        Me.btnDZHome.Text = "Z: Home"
        Me.btnDZHome.UseVisualStyleBackColor = True
        '
        'txtDZMove
        '
        Me.txtDZMove.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.txtDZMove.Location = New System.Drawing.Point(732, 44)
        Me.txtDZMove.Name = "txtDZMove"
        Me.txtDZMove.Size = New System.Drawing.Size(80, 26)
        Me.txtDZMove.TabIndex = 124
        '
        'btnDZDown
        '
        Me.btnDZDown.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnDZDown.Location = New System.Drawing.Point(732, 74)
        Me.btnDZDown.Name = "btnDZDown"
        Me.btnDZDown.Size = New System.Drawing.Size(80, 30)
        Me.btnDZDown.TabIndex = 123
        Me.btnDZDown.Text = "Z:   ↓↓↓"
        Me.btnDZDown.UseVisualStyleBackColor = True
        '
        'btnDZUp
        '
        Me.btnDZUp.Font = New System.Drawing.Font("Microsoft Sans Serif", 12.0!)
        Me.btnDZUp.Location = New System.Drawing.Point(732, 9)
        Me.btnDZUp.Name = "btnDZUp"
        Me.btnDZUp.Size = New System.Drawing.Size(80, 30)
        Me.btnDZUp.TabIndex = 122
        Me.btnDZUp.Text = "Z:  ↑↑↑"
        Me.btnDZUp.UseVisualStyleBackColor = True
        '
        'PictureBox4
        '
        Me.PictureBox4.Image = Global.Drops_Mechanism_GUI.My.Resources.Resources.XYZ
        Me.PictureBox4.InitialImage = Global.Drops_Mechanism_GUI.My.Resources.Resource1.XYZ
        Me.PictureBox4.Location = New System.Drawing.Point(562, 268)
        Me.PictureBox4.Name = "PictureBox4"
        Me.PictureBox4.Size = New System.Drawing.Size(250, 106)
        Me.PictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox4.TabIndex = 140
        Me.PictureBox4.TabStop = False
        '
        'PictureBox3
        '
        Me.PictureBox3.Image = Global.Drops_Mechanism_GUI.My.Resources.Resource1.drops_generator
        Me.PictureBox3.InitialImage = Global.Drops_Mechanism_GUI.My.Resources.Resource1.XYZ
        Me.PictureBox3.Location = New System.Drawing.Point(562, 9)
        Me.PictureBox3.Name = "PictureBox3"
        Me.PictureBox3.Size = New System.Drawing.Size(164, 160)
        Me.PictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox3.TabIndex = 134
        Me.PictureBox3.TabStop = False
        '
        'PictureBox2
        '
        Me.PictureBox2.Image = Global.Drops_Mechanism_GUI.My.Resources.Resource1.wave_generator
        Me.PictureBox2.InitialImage = Global.Drops_Mechanism_GUI.My.Resources.Resource1.XYZ
        Me.PictureBox2.Location = New System.Drawing.Point(1020, 203)
        Me.PictureBox2.Name = "PictureBox2"
        Me.PictureBox2.Size = New System.Drawing.Size(250, 160)
        Me.PictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox2.TabIndex = 116
        Me.PictureBox2.TabStop = False
        '
        'PictureBox1
        '
        Me.PictureBox1.Image = Global.Drops_Mechanism_GUI.My.Resources.Resource1.laser_camera
        Me.PictureBox1.InitialImage = Global.Drops_Mechanism_GUI.My.Resources.Resource1.XYZ
        Me.PictureBox1.Location = New System.Drawing.Point(562, 470)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(250, 160)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox1.TabIndex = 98
        Me.PictureBox1.TabStop = False
        '
        'PictureBox5
        '
        Me.PictureBox5.Image = Global.Drops_Mechanism_GUI.My.Resources.Resource1.cofocal_sensor
        Me.PictureBox5.InitialImage = Global.Drops_Mechanism_GUI.My.Resources.Resource1.XYZ
        Me.PictureBox5.Location = New System.Drawing.Point(106, 203)
        Me.PictureBox5.Name = "PictureBox5"
        Me.PictureBox5.Size = New System.Drawing.Size(250, 160)
        Me.PictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom
        Me.PictureBox5.TabIndex = 81
        Me.PictureBox5.TabStop = False
        '
        'MainWindow
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(1589, 736)
        Me.Controls.Add(Me.PictureBox4)
        Me.Controls.Add(Me.Label10)
        Me.Controls.Add(Me.Label11)
        Me.Controls.Add(Me.PictureBox3)
        Me.Controls.Add(Me.btnDZHome)
        Me.Controls.Add(Me.txtDZMove)
        Me.Controls.Add(Me.btnDZDown)
        Me.Controls.Add(Me.btnDZUp)
        Me.Controls.Add(Me.Label6)
        Me.Controls.Add(Me.Label7)
        Me.Controls.Add(Me.Label8)
        Me.Controls.Add(Me.Label9)
        Me.Controls.Add(Me.btnWXYZHome)
        Me.Controls.Add(Me.PictureBox2)
        Me.Controls.Add(Me.txtWYMove)
        Me.Controls.Add(Me.btnWXHome)
        Me.Controls.Add(Me.txtWXMove)
        Me.Controls.Add(Me.btnWXLeft)
        Me.Controls.Add(Me.btnWXRight)
        Me.Controls.Add(Me.btnWYHome)
        Me.Controls.Add(Me.btnWZHome)
        Me.Controls.Add(Me.btnWYBackward)
        Me.Controls.Add(Me.btnWYForward)
        Me.Controls.Add(Me.txtWZMove)
        Me.Controls.Add(Me.btnWZDown)
        Me.Controls.Add(Me.btnWZUp)
        Me.Controls.Add(Me.Label1)
        Me.Controls.Add(Me.Label2)
        Me.Controls.Add(Me.Label3)
        Me.Controls.Add(Me.Label5)
        Me.Controls.Add(Me.btnCXYZHome)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.txtCYMove)
        Me.Controls.Add(Me.btnCXHome)
        Me.Controls.Add(Me.txtCXMove)
        Me.Controls.Add(Me.btnCXLeft)
        Me.Controls.Add(Me.btnCXRight)
        Me.Controls.Add(Me.btnCYHome)
        Me.Controls.Add(Me.btnCZHome)
        Me.Controls.Add(Me.btnCYBackward)
        Me.Controls.Add(Me.btnCYForward)
        Me.Controls.Add(Me.txtCZMove)
        Me.Controls.Add(Me.btnCZDown)
        Me.Controls.Add(Me.btnCZUp)
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
        CType(Me.PictureBox4, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox3, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox2, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
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
    Friend WithEvents Label1 As Label
    Friend WithEvents Label2 As Label
    Friend WithEvents Label3 As Label
    Friend WithEvents Label5 As Label
    Friend WithEvents btnCXYZHome As Button
    Friend WithEvents PictureBox1 As PictureBox
    Friend WithEvents txtCYMove As TextBox
    Friend WithEvents btnCXHome As Button
    Friend WithEvents txtCXMove As TextBox
    Friend WithEvents btnCXLeft As Button
    Friend WithEvents btnCXRight As Button
    Friend WithEvents btnCYHome As Button
    Friend WithEvents btnCZHome As Button
    Friend WithEvents btnCYBackward As Button
    Friend WithEvents btnCYForward As Button
    Friend WithEvents txtCZMove As TextBox
    Friend WithEvents btnCZDown As Button
    Friend WithEvents btnCZUp As Button
    Friend WithEvents Label6 As Label
    Friend WithEvents Label7 As Label
    Friend WithEvents Label8 As Label
    Friend WithEvents Label9 As Label
    Friend WithEvents btnWXYZHome As Button
    Friend WithEvents PictureBox2 As PictureBox
    Friend WithEvents txtWYMove As TextBox
    Friend WithEvents btnWXHome As Button
    Friend WithEvents txtWXMove As TextBox
    Friend WithEvents btnWXLeft As Button
    Friend WithEvents btnWXRight As Button
    Friend WithEvents btnWYHome As Button
    Friend WithEvents btnWZHome As Button
    Friend WithEvents btnWYBackward As Button
    Friend WithEvents btnWYForward As Button
    Friend WithEvents txtWZMove As TextBox
    Friend WithEvents btnWZDown As Button
    Friend WithEvents btnWZUp As Button
    Friend WithEvents Label10 As Label
    Friend WithEvents Label11 As Label
    Friend WithEvents PictureBox3 As PictureBox
    Friend WithEvents btnDZHome As Button
    Friend WithEvents txtDZMove As TextBox
    Friend WithEvents btnDZDown As Button
    Friend WithEvents btnDZUp As Button
    Friend WithEvents PictureBox4 As PictureBox
End Class
