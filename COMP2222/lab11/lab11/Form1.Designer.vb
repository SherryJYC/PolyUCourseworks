<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
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
    Me.Button1 = New System.Windows.Forms.Button()
    Me.Button2 = New System.Windows.Forms.Button()
    Me.Button3 = New System.Windows.Forms.Button()
    Me.TextBox1 = New System.Windows.Forms.TextBox()
    Me.TextBox2 = New System.Windows.Forms.TextBox()
    Me.ProgressBar1 = New System.Windows.Forms.ProgressBar()
    Me.Label1 = New System.Windows.Forms.Label()
    Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
    Me.OpenFileDialog1 = New System.Windows.Forms.OpenFileDialog()
    Me.SaveFileDialog1 = New System.Windows.Forms.SaveFileDialog()
    Me.CheckedListBox1 = New System.Windows.Forms.CheckedListBox()
    Me.SuspendLayout()
    '
    'Button1
    '
    Me.Button1.Location = New System.Drawing.Point(14, 55)
    Me.Button1.Name = "Button1"
    Me.Button1.Size = New System.Drawing.Size(73, 27)
    Me.Button1.TabIndex = 0
    Me.Button1.Text = "Open"
    Me.Button1.UseVisualStyleBackColor = True
    '
    'Button2
    '
    Me.Button2.Location = New System.Drawing.Point(13, 107)
    Me.Button2.Name = "Button2"
    Me.Button2.Size = New System.Drawing.Size(73, 30)
    Me.Button2.TabIndex = 1
    Me.Button2.Text = "Save"
    Me.Button2.UseVisualStyleBackColor = True
    '
    'Button3
    '
    Me.Button3.Location = New System.Drawing.Point(87, 163)
    Me.Button3.Name = "Button3"
    Me.Button3.Size = New System.Drawing.Size(122, 39)
    Me.Button3.TabIndex = 2
    Me.Button3.Text = "Start"
    Me.Button3.UseVisualStyleBackColor = True
    '
    'TextBox1
    '
    Me.TextBox1.Location = New System.Drawing.Point(100, 58)
    Me.TextBox1.Name = "TextBox1"
    Me.TextBox1.Size = New System.Drawing.Size(160, 21)
    Me.TextBox1.TabIndex = 3
    '
    'TextBox2
    '
    Me.TextBox2.Location = New System.Drawing.Point(100, 114)
    Me.TextBox2.Name = "TextBox2"
    Me.TextBox2.Size = New System.Drawing.Size(156, 21)
    Me.TextBox2.TabIndex = 4
    '
    'ProgressBar1
    '
    Me.ProgressBar1.Dock = System.Windows.Forms.DockStyle.Bottom
    Me.ProgressBar1.Location = New System.Drawing.Point(0, 249)
    Me.ProgressBar1.Name = "ProgressBar1"
    Me.ProgressBar1.Size = New System.Drawing.Size(323, 41)
    Me.ProgressBar1.TabIndex = 5
    '
    'Label1
    '
    Me.Label1.AutoSize = True
    Me.Label1.Location = New System.Drawing.Point(26, 223)
    Me.Label1.Name = "Label1"
    Me.Label1.Size = New System.Drawing.Size(0, 12)
    Me.Label1.TabIndex = 6
    '
    'Timer1
    '
    '
    'OpenFileDialog1
    '
    Me.OpenFileDialog1.FileName = "OpenFileDialog1"
    '
    'CheckedListBox1
    '
    Me.CheckedListBox1.FormattingEnabled = True
    Me.CheckedListBox1.Items.AddRange(New Object() {"3", "1", "3"})
    Me.CheckedListBox1.Location = New System.Drawing.Point(100, -2)
    Me.CheckedListBox1.Name = "CheckedListBox1"
    Me.CheckedListBox1.Size = New System.Drawing.Size(120, 84)
    Me.CheckedListBox1.TabIndex = 7
    '
    'Form1
    '
    Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 12.0!)
    Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
    Me.ClientSize = New System.Drawing.Size(323, 290)
    Me.Controls.Add(Me.CheckedListBox1)
    Me.Controls.Add(Me.Label1)
    Me.Controls.Add(Me.ProgressBar1)
    Me.Controls.Add(Me.TextBox2)
    Me.Controls.Add(Me.TextBox1)
    Me.Controls.Add(Me.Button3)
    Me.Controls.Add(Me.Button2)
    Me.Controls.Add(Me.Button1)
    Me.Name = "Form1"
    Me.Text = "Form1"
    Me.ResumeLayout(False)
    Me.PerformLayout()

  End Sub

  Friend WithEvents Button1 As Button
    Friend WithEvents Button2 As Button
    Friend WithEvents Button3 As Button
    Friend WithEvents TextBox1 As TextBox
    Friend WithEvents TextBox2 As TextBox
    Friend WithEvents ProgressBar1 As ProgressBar
    Friend WithEvents Label1 As Label
    Friend WithEvents Timer1 As Timer
    Friend WithEvents OpenFileDialog1 As OpenFileDialog
    Friend WithEvents SaveFileDialog1 As SaveFileDialog
  Friend WithEvents CheckedListBox1 As CheckedListBox
End Class
