# Google App Engine Modules
import logging
import webapp2
from google.appengine.ext.webapp.mail_handlers import InboundMailHandler

# Project Specific Modules
from ndb_entities.py import EmailPacket

class LogSenderHandler(InboundMailHandler):
    def receive(self, mail_message):
        logging.info("Received a message from: " + mail_message.sender)
        plaintext_bodies = mail_message.bodies('text/plain')
        html_bodies = mail_message.bodies('text/html')

        for content_type, body in html_bodies:
            decoded_html = body.decode()
            logging.info("Html body of length %d.", len(decoded_html))

        for content_type, body in plaintext_bodies:
            plaintext = body.decode()
            logging.info("Plain text body of length %d.", len(plaintext))

        newEntry = EmailPacket(source=mail_message.sender, body=plaintext_bodies)
        newKey = newEntry.put()

app = webapp2.WSGIApplication([LogSenderHandler.mapping()], debug=True)
