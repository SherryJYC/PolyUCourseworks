Imports Scripting

Public Class Form1

  Dim _src, _dst As String
  Dim _file As FileSystemObject = New FileSystemObject
  Dim _srcSize As Double

  Private Sub Button1_Click(sender As Object, e As EventArgs) Handles Button1.Click
    OpenFileDialog1.InitialDirectory = "C:\"
    OpenFileDialog1.Filter = "Text Document (*.txt)|*.txt|All Files (*.*)|*.*"
    OpenFileDialog1.Title = "Open _file Dialog"
    If OpenFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
      MsgBox(OpenFileDialog1.FileName)
      _src = OpenFileDialog1.FileName
      TextBox1.Text = _src
    End If

    ResetThings()
    Timer1.Stop()
  End Sub

  Private Sub Button2_Click(sender As Object, e As EventArgs) Handles Button2.Click
    With SaveFileDialog1
      .DefaultExt = "txt"
      .FileName = _src
      .Filter = "Text Document (*.txt)|*.txt|All Files (*.*)|*.*"
      .Title = "Save _file Dialog"
    End With
    If SaveFileDialog1.ShowDialog() = System.Windows.Forms.DialogResult.OK Then
      _dst = SaveFileDialog1.FileName
      MsgBox(SaveFileDialog1.FileName)
      TextBox2.Text = _dst
    End If
  End Sub


  Private Sub Button3_Click(sender As Object, e As EventArgs) Handles Button3.Click
    FileCopy(_src, _dst)
    Timer1.Start()
  End Sub

  Private Sub Timer1_Tick(sender As Object, e As EventArgs) Handles Timer1.Tick
    Dim s, d As System.IO.FileInfo
    s = My.Computer.FileSystem.GetFileInfo(_src)
    d = My.Computer.FileSystem.GetFileInfo(_dst)
    Dim percent As Integer = d.Length / s.Length * 100
    If d.Length = -1 Then
      ResetThings()
    Else
      Label1.Text = percent & "% Percent"
      ProgressBar1.Value = percent
    End If
  End Sub

  Private Sub ResetThings()
    ProgressBar1.Value = 0
    Label1.Text = ""
  End Sub
End Class