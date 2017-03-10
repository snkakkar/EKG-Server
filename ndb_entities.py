from google.appengine.ext import ndb

'''
CLASS:  Packet
DESCRIPTION: An NDB model which stores an individual email-packet's worth of
data. This includes fields for the sender, sequence number, and body of the
email.
'''
class EmailPacket(ndb.Model):
    source = ndb.StringProperty() #Email or Phone number this packet originated from
    sequence = ndb.IntegerProperty() #The 
    body = ndb.StringProperty()
