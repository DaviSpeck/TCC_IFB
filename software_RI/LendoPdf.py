import PyPDF2
import re
import sys

arquivo = open(
    r'texto.pdf', 'rb')
read_pdf = PyPDF2.PdfFileReader(arquivo)

n = read_pdf.numPages

txt = ''

for i in range(0, n):
    page = read_pdf.getPage(i)
    page_content = page.extractText()
    parsed = ''.join(page_content)
    parsed = re.sub('\n', '', parsed)
    txt += '\n' + "Página {}".format(i + 1) + '\n'
    txt += parsed.encode('cp1252', errors='replace').decode('cp1252') + '\n'


arquivo = open(
    'texto.txt', 'w', encoding='utf-8')
arquivo.write(txt)
