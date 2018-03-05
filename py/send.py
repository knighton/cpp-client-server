from argparse import ArgumentParser
import requests
import ujson as json


def parse_args():
    ap = ArgumentParser()
    ap.add_argument('--server_host', type=str, default='localhost',
                    help='Server host.')
    ap.add_argument('--server_port', type=int, default=1337,    
                    help='Server port.')
    return ap.parse_args()


def run(args):
    x = {
        'a': 123.456,
        'b': [1, 2, 3, 'Go!'],
    }
    url = 'http://%s:%d/json' % (args.server_host, args.server_port)
    ret = requests.post(url, json.dumps(x))
    print('Status code: %d' % ret.status_code)
    print('Body: %s' % ret.text)


if __name__ == '__main__':
    run(parse_args())
