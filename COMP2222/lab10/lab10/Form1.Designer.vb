<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
  Inherits System.Windows.Forms.Form

  'Form 重写 Dispose，以清理组件列表。
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

  'Windows 窗体设计器所必需的
  Private components As System.ComponentModel.IContainer

  '注意: 以下过程是 Windows 窗体设计器所必需的
  '可以使用 Windows 窗体设计器修改它。  
  '不要使用代码编辑器修改它。
  <System.Diagnostics.DebuggerStepThrough()> _
  Private Sub InitializeComponent()
    Me.components = New System.ComponentModel.Container()
    Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
    Me.PictureBox1 = New System.Windows.Forms.PictureBox()
    Me.GroupBox1 = New System.Windows.Forms.GroupBox()
    Me.RadioButton1 = New System.Windows.Forms.RadioButton()
    Me.RadioButton2 = New System.Windows.Forms.RadioButton()
    CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
    Me.GroupBox1.SuspendLayout()
    Me.SuspendLayout()
    '
    'Timer1
    '
    Me.Timer1.Enabled = True
    Me.Timer1.Interval = 1
    '
    'PictureBox1
    '
    Me.PictureBox1.Image = Global.lab10.My.Resources.Resources.bat_1
    Me.PictureBox1.Location = New System.Drawing.Point(28, 12)
    Me.PictureBox1.Name = "PictureBox1"
    Me.PictureBox1.Size = New System.Drawing.Size(287, 281)
    Me.PictureBox1.TabIndex = 0
    Me.PictureBox1.TabStop = False
    '
    'GroupBox1
    '
    Me.GroupBox1.Controls.Add(Me.RadioButton2)
    Me.GroupBox1.Controls.Add(Me.RadioButton1)
    Me.GroupBox1.Location = New System.Drawing.Point(480, 96)
    Me.GroupBox1.Name = "GroupBox1"
    Me.GroupBox1.Size = New System.Drawing.Size(200, 100)
    Me.GroupBox1.TabIndex = 1
    Me.GroupBox1.TabStop = False
    Me.GroupBox1.Text = "GroupBox1"
    '
    'RadioButton1
    '
    Me.RadioButton1.AutoSize = True
    Me.RadioButton1.Location = New System.Drawing.Point(7, 21)
    Me.RadioButton1.Name = "RadioButton1"
    Me.RadioButton1.Size = New System.Drawing.Size(95, 16)
    Me.RadioButton1.TabIndex = 0
    Me.RadioButton1.TabStop = True
    Me.RadioButton1.Text = "RadioButton1"
    Me.RadioButton1.UseVisualStyleBackColor = True
    '
    'RadioButton2
    '
    Me.RadioButton2.AutoSize = True
    Me.RadioButton2.Location = New System.Drawing.Point(7, 44)
    Me.RadioButton2.Name = "RadioButton2"
    Me.RadioButton2.Size = New System.Drawing.Size(95, 16)
    Me.RadioButton2.TabIndex = 1
    Me.RadioButton2.TabStop = True
    Me.RadioButton2.Text = "RadioButton2"
    Me.RadioButton2.UseVisualStyleBackColor = True
    '
    'Form1
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.ClientSize = New System.Drawing.Size(1213, 446)
    Me.Controls.Add(Me.GroupBox1)
    Me.Controls.Add(Me.PictureBox1)
    Me.Name = "Form1"
    Me.Text = "Form1"
    CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
    Me.GroupBox1.ResumeLayout(False)
    Me.GroupBox1.PerformLayout()
    Me.ResumeLayout(False)

  End Sub

  Friend WithEvents Timer1 As Timer
  Friend WithEvents PictureBox1 As PictureBox
  Friend WithEvents GroupBox1 As GroupBox
  Friend WithEvents RadioButton2 As RadioButton
  Friend WithEvents RadioButton1 As RadioButton
End Class
