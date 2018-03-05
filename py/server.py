from argparse import ArgumentParser
from flask import Flask, request
import logging
import ujson as json


def parse_args():
    ap = ArgumentParser()
    ap.add_argument('--port', type=int, default=1337, help='Port to serve on.')
    return ap.parse_args()


def run(args):
    app = Flask(__name__)

    @app.route('/')
    def route_root():
        print('/')
        return 'Hello world!'

    @app.route('/json', methods=['POST'])
    def route_json():
        print('/json')
        x = json.loads(request.data)
        ret = {'result': x['a']}
        return json.dumps(ret)

    @app.route('/stop', methods=['POST'])
    def route_stop():
        print('/stop')
        try:
            f = request.environ.get('werkzeug.server.shutdown')
            f()
        except:
            pass
        return ''

    log = logging.getLogger('werkzeug')
    log.setLevel(logging.ERROR)

    app.run(host='0.0.0.0', port=args.port)


if __name__ == '__main__':
    run(parse_args())
