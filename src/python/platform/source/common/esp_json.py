import sys, time
import json

def ESP_JSON_getJsonValue(key):
	with open('esp.json','r',encoding='utf8')as fp:
		json_data = json.load(fp)
		if (json_data[key] != None):
			return json_data[key]