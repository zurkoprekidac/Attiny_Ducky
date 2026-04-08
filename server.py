import flask
from flask import Flask, request, jsonify

#request example
#curl -i -H "Content-type: application/json" -X POST -d '{"ime":"rsMIKA", "metod":"UTAKNUTI", "vreme":"0709211846"}' http://localhost:5000/db/ulovljeni/

app = Flask(__name__,  static_url_path = "", static_folder = "img")

db=[
 {
 'ime':'randomime',
 'metod':'KLIKNUTI',
 'vreme':'0709211822'
 },
 {
 'ime':'drugoime',
 'metod':'UTAKNUTI',
 'vreme':'0709211011'
 }
 ]

@app.route("/")
def frontPage():
    return "<html><head><title>Test Stranica</title></head><body><p><img src=wall.jpg alt=wall></p>"

@app.route('/db/ulovljeni/',methods=['POST'])
def createEmp(): 
    dat = {
    'ime':request.json['ime'],
    'metod':request.json['metod'],
    'vreme':request.json['vreme']
    }
    db.append(dat)
    file = open("baza.txt", "a")
    podaci = repr(dat)
    #file.write("usr = " + str_dictionary + "\n")
    file.write(podaci + "\n")
    file.close()
    return ('', 204)
    
if __name__ == "__main__":
	app.run()
