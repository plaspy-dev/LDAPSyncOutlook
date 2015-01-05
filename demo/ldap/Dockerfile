FROM debian:bookworm-slim@sha256:734a72b3d6142a71993b4bc580ca01d8ca687f77a2c422d96a961d3376b179bc
RUN apt-get update && DEBIAN_FRONTEND=noninteractive apt-get install --no-install-recommends -y slapd ldap-utils && rm -rf /var/lib/apt/lists/*
COPY slapd.conf synthetic.ldif /fixture/
EXPOSE 389
CMD ["sh", "-ec", "mkdir -p /tmp/demo-db; slapadd -f /fixture/slapd.conf -l /fixture/synthetic.ldif; exec slapd -f /fixture/slapd.conf -h ldap://0.0.0.0:389/ -d 256"]
