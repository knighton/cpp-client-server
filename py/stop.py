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
    url = 'http://%s:%d/stop' % (args.server_host, args.server_port)
    ret = requests.post(url)
    print('Status code: %d' % ret.status_code)
    print('Body: %s' % ret.text)


if __name__ == '__main__':
    run(parse_args())
