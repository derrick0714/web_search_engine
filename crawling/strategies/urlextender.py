'''
Created on Feb 14, 2013

@author: Adam57
'''
class URLExtender(object):
    def ExtendURL(self, child, parent):
        child._url = parent._url + child._url
        