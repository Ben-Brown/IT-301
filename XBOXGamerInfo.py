import urllib2
import json
import win32com.client

#Importing both codecs and sys libraries allow for special translation so that the script is readable by Python
import codecs, sys
sys.stdout = codecs.getwriter('UTF-8')(sys.stdout)

#Prompts the user to enter his/her Gamertag.
handle = raw_input ("Please enter your XBOX LIVE Gamertag >> ")

#'response' is the variable assigned to the URL that retrieves the Gamer's information.
response = urllib2.urlopen("https://xboxapi.com/games/%s" % handle)

#'json_data' is the variable assigned to represent all of the information that is retrieved from the user specific XBOX LIVE Gamer Profile. 
json_data = json.load(response)

#Launch or connect to Microsoft Excel.
x = win32com.client.Dispatch("Excel.Application")
x.Visible = 1
x.Workbooks.Add()

#Despite the alphanumeric layout of Microsoft Excel's rows and columns, both the rows and columns are represented numerically in Python. The first number appearing in the coordinates represents the column number while the second number in the coordinates represents the rows of the Excel spreadsheet.
x.Range(1,1).Value = "Gamertag"
x.Range(1,1).ColumnWidth = 20

x.Range(1,2).Value = handle
x.Range(1,2).ColumnWidth = 20

x.Range(2,1).Value = "Gamer Score"
x.Range(2,1).ColumnWidth = 15

x.Range(2,2).Value = json_data['Player']['Gamerscore']
x.Range(2,2).ColumnWidth = 20

x.Range(3,1).Value = "Game Count"
x.Range(3,1).ColumnWidth = 15 

x.Range(3,2).Value = json_data['Player']['GameCount']
x.Range(3,2).ColumnWidth = 20

for game in json_data ['Games']:
	x.Range("A:A").ColumnWidth = 25
	x.Range(5,1).Value = "Title"
	x.Range(5,2).Value = json_data['Name']
	x.Range(6,1).Value = "Possible Score"
	x.Range(6,2).Value = json_data['Games']['PossibleScore']
	x.Range(7,1).Value = "Possible Achievements"
	x.Range(7,2).Value = json_data['Games']['PossibleAchievements']
	x.Range(8,1).Value = "Achievements"
	x.Range(8,2).Value = json_data['Games']['Progress']['Achievements']

