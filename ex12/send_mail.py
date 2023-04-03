import smtplib
import os.path
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.application import MIMEApplication

# Set up the SMTP server and login with your credentials
smtp_server = 'smtp.gmail.com'
smtp_port = 587
smtp_username = 'abdessamadlaamimi@gmail.com'
smtp_password = 'reveltmyerilntvo'
smtp_sender = smtp_username
smtp_recipient = 'abdessamadlaamimi@gmail.com'

# Create a multipart message
message = MIMEMultipart()
message['From'] = smtp_sender
message['To'] = smtp_recipient
message['Subject'] = 'Test email with attachment'

# Add the message body
text = MIMEText('Hey, this was sent using Python')
message.attach(text)

# Add the attachment
filename = '/tmp/test.txt'
filepath = os.path.join(os.path.dirname(__file__), filename)
with open(filepath, 'rb') as f:
    attachment = MIMEApplication(f.read(), _subtype='txt')
    attachment.add_header('Content-Disposition', 'attachment', filename=filename)
    message.attach(attachment)

# Send the email
with smtplib.SMTP(smtp_server, smtp_port) as server:
    server.starttls()
    server.login(smtp_username, smtp_password)
    server.sendmail(smtp_sender, smtp_recipient, message.as_string())

print("Email sent successfully!")
